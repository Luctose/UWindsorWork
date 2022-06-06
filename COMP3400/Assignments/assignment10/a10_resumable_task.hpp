#ifndef comp3400_2022w_preney_resumable_task_hpp_
#define comp3400_2022w_preney_resumable_task_hpp_

//===========================================================================

#include <optional>
#include <coroutine>
#include <exception>
#include <stdexcept>

//===========================================================================

//
// resumable_task_start, resumable_task_stop
// enumerations
//
// These enumerations allow one to start whether or not something is
// immediately started/stopped or such is deferred.
//
enum class resumable_task_start { immediate, deferred };
enum class resumable_task_stop { immediate, deferred };

//===========================================================================

//
// resumeable_task_promise<Ret,Start,Stop>
// class
//
// This promise:
//   * allows co_yield to return objects of type Ret
//   * co_return must never return a value
//   * co_await is not prohibited (but nothing is done in this definition)
//   * Start defines if code is initially run or suspended.
//     e.g., if immediate, then initial execution runs until the first
//           co_yield (if any is present) or suitable co_await (if any
//           is present and actually suspends)
//   * Stop defines if termination is deferred or not.
//
// Since each coroutine function, cf, is transformed into:
//
//   {
//       co_await promise.initial_suspend();
//       try { cf(); } catch (...) { promise.unhandled_exception(); }
//     final_suspend:
//       co_await promise.final_suspend();
//   }
//
// setting Start affects initial_suspend() and Stop affects final_suspend().
//
template <typename T, resumable_task_start Start, resumable_task_stop Stop>
struct resumable_task_promise
{
  std::optional<T> value_;
  std::exception_ptr exception_;

  auto get_return_object() noexcept
  {
    return std::coroutine_handle<resumable_task_promise>::
      from_promise(*this);
  }

  auto initial_suspend() noexcept
  {
    if constexpr(Start == resumable_task_start::immediate)
      return std::suspend_never{};
    else
      return std::suspend_always{};
  }

  auto final_suspend() noexcept
  {
    if constexpr(Stop == resumable_task_stop::immediate)
      return std::suspend_never{};
    else
      return std::suspend_always{};
  }

  template <std::convertible_to<T> From>
  std::suspend_always yield_value(From&& from)
  {
    value_ = std::forward<From>(from);
    return {};
  }

  // co_return for resumable_task_promise will not accept a return value
  void return_void() noexcept
  {
  }

  void unhandled_exception() noexcept
  {
    exception_ = std::current_exception();
  }
};

//---------------------------------------------------------------------------

//
// resumable_task_promise<void,Start,Stop>
// partial specialization for void
//
// If the return type is void, then the only thing that can be
// "returned" is an exception, i.e., there is no need to store
// std::optional<void>, etc. This specialization addresses such.
//
template <resumable_task_start Start, resumable_task_stop Stop>
struct resumable_task_promise<void,Start,Stop>
{
  std::exception_ptr exception_;

  auto get_return_object() noexcept
  {
    return std::coroutine_handle<resumable_task_promise>::
      from_promise(*this);
  }

  auto initial_suspend() noexcept
  {
    if constexpr(Start == resumable_task_start::immediate)
      return std::suspend_never{};
    else
      return std::suspend_always{};
  }

  auto final_suspend() noexcept
  {
    if constexpr(Stop == resumable_task_stop::immediate)
      return std::suspend_never{};
    else
      return std::suspend_always{};
  }

  // intentionally ignore anything passed to co_yield
  template <typename From>
  std::suspend_always yield_value(From&&) noexcept
  {
    return {};
  }

  void return_void() noexcept
  {
  }

  void unhandled_exception() noexcept
  {
    exception_ = std::current_exception();
  }
};

//===========================================================================

template <
  typename T = void,
  resumable_task_start Start = resumable_task_start::deferred, 
  resumable_task_stop Stop = resumable_task_stop::deferred
>
class resumable_task
{
public:
  using value_type = T;
  using promise_type = resumable_task_promise<value_type,Start,Stop>;

private:
  std::coroutine_handle<promise_type> handle_;

public:
  resumable_task(std::coroutine_handle<promise_type> const& h) :
    handle_{h}
  {
  }

  resumable_task(std::coroutine_handle<promise_type>&& h) :
    handle_{std::move(h)}
  {
  }

  ~resumable_task()
  {
    if (handle_)
      handle_.destroy();
  }

  // prohibit copies...
  resumable_task(resumable_task const&) = delete;
  resumable_task& operator=(resumable_task const&) = delete;

  // premit move construction...
  resumable_task(resumable_task&& other) noexcept :
    handle_{std::move(other.handle_)}
  {
    other.handle_ = nullptr;
  }

  // permit move assignment only for lvalues...
  resumable_task& operator=(resumable_task&& other) noexcept
  {
    resumable_task local(std::move(other));
    swap(local);
    return *this;
  }

  void swap(resumable_task& other) noexcept
  {
    auto tmp = std::move(handle_);
    handle_ = std::move(other.handle_);
    other.handle_ = std::move(tmp);
  }

  bool is_resumable() const noexcept
  {
    if (!handle_)
      return false;
    return handle_.promise().exception_ || !handle_.done();
  }

  void resume() const
  {
    handle_.resume();
  }

  bool valid() const
  {
    return handle_.promise().exception_ || handle_.promise().value_;
  }

  operator bool() const
  {
    return valid();
  }

  value_type& get() &
  {
    if (handle_.promise().exception_)
      std::rethrow_exception(handle_.promise().exception_);
    return *handle_.promise().value_;
  }
  
  value_type const& get() const&
  {
    if (handle_.promise().exception_)
      std::rethrow_exception(handle_.promise().exception_);
    return *handle_.promise().value_;
  }
  
  value_type&& get() &&
  {
    if (handle_.promise().exception_)
      std::rethrow_exception(handle_.promise().exception_);
    return *handle_.promise().value_;
  }
};

//---------------------------------------------------------------------------

//
// resumable_task<void,Start,Stop>
// partial specialization for void
//
// If the return type is void, then the only thing that can be
// "returned" is an exception, i.e., there is no need to store
// std::optional<void>. This specialization addresses such.
//
template <resumable_task_start Start, resumable_task_stop Stop>
class resumable_task<void,Start,Stop>
{
public:
  using value_type = void;
  using promise_type = resumable_task_promise<void,Start,Stop>;

private:
  std::coroutine_handle<promise_type> handle_;

public:
  resumable_task(std::coroutine_handle<promise_type> const& h) :
    handle_{h}
  {
  }

  resumable_task(std::coroutine_handle<promise_type>&& h) :
    handle_{std::move(h)}
  {
  }

  ~resumable_task()
  {
    if (handle_)
      handle_.destroy();
  }

  // prohibit copies...
  resumable_task(resumable_task const&) = delete;
  resumable_task& operator=(resumable_task const&) = delete;

  // premit move construction...
  resumable_task(resumable_task&& other) noexcept :
    handle_{std::move(other.handle_)}
  {
    other.handle_ = nullptr;
  }

  // permit move assignment only for lvalues...
  resumable_task& operator=(resumable_task&& other) noexcept
  {
    resumable_task local(std::move(other));
    swap(local);
    return *this;
  }

  void swap(resumable_task& other) noexcept
  {
    auto tmp = std::move(handle_);
    handle_ = std::move(other.handle_);
    other.handle_ = std::move(tmp);
  }

  bool is_resumable() const noexcept
  {
    if (!handle_)
      return false;
    return handle_.promise().exception_ || !handle_.done();
  }

  void resume() const
  {
    handle_.resume();
  }

  bool valid() const
  {
    return handle_.promise().exception_;
  }

  operator bool() const
  {
    return valid();
  }

  void get()
  {
    if (handle_.promise().exception_)
      std::rethrow_exception(handle_.promise().exception_);
  }
};

//=====

template <typename... Types, auto... Values>
inline void swap(
  resumable_task<Types...,Values...>& a, 
  resumable_task<Types...,Values...>& b
)
  noexcept
{
  a.swap(b);
}

//===========================================================================

#endif // #ifndef comp3400_2022w_preney_resumable_task_hpp_
