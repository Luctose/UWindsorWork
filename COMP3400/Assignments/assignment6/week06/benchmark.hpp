#ifndef comp3400_2020w_benchmark_hpp_
#define comp3400_2020w_benchmark_hpp_

//===========================================================================

#include <chrono>
#include "tally.hpp"

//===========================================================================

#if defined(__GNUC__)
inline void do_not_optimize_barrier()
{
  asm volatile("" ::: "memory"); // GCC specific
}
#else
#  error "Need to write a compile-specific definition of do_not_optimize_barrier()"
#endif

//==========================================================================

template <typename Int, typename Op, typename... Args>
tally simple_benchmark(Int const& num_iters, Op&& op, Args&&... args)
{
  using namespace std;
  using namespace std::chrono;

  tally t;
  for (Int i{}; i != num_iters; ++i)
  {
    do_not_optimize_barrier();

    auto time0 = steady_clock::now();

    do_not_optimize_barrier();

    if constexpr(!is_void_v<decltype(op(args...))>)
      [[maybe_unused]] auto result = op(args...);
    else
      op(args...);

    do_not_optimize_barrier();

    auto time1 = steady_clock::now();

    do_not_optimize_barrier();

    t += duration<double>(time1-time0).count();
  }
  return t;
}

//===========================================================================

#endif // #ifndef comp3400_2020w_benchmark_hpp_
