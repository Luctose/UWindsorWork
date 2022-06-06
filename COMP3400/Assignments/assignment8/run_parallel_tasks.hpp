#ifndef comp3400_2020w_run_parallel_tasks_hpp_
#define comp3400_2020w_run_parallel_tasks_hpp_

//===========================================================================

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

//===========================================================================

// Define a simple run_parallel_tasks class...
class run_parallel_tasks
{
private:
  using task_type = std::function<void()>;

  std::atomic<bool> abort_requested_;
  std::atomic<bool> stop_requested_;
  std::vector<std::thread> threads_;

  std::queue<task_type> q_;
  std::mutex m_;
  std::condition_variable_any enq_deq_cv_;

  // worker() runs a task enqueued in q_ removing that task from the queue...
  void worker()
  {
    for (bool not_done{true}; not_done; )
    {
      task_type task;

      // Define aa code block to wait, hold, and free a lock...
      {
        // Wait until there is something enqueued...
        std::unique_lock<std::mutex> lock(m_);
        // wait until q_ is not empty...
        enq_deq_cv_.wait(
          lock, 
          [this]() { return !q_.empty() || stop_requested_; }
        );

        // After waiting, this worker now owns the lock, so
        // dequeue the task at the front of q_.
        if (abort_requested_)
          break; // short-circuit worker termination
        else if (!q_.empty())
        {
          task = move(q_.front());
          q_.pop();
        }
        else if (stop_requested_)
          not_done = false;
      }

      // Let another thread know something can be done...
      enq_deq_cv_.notify_one();

      // Execute the task eating all exceptions...
      try { if (task) task(); } catch (...) { }
    }
  }

public:
  run_parallel_tasks(std::size_t num_threads=std::thread::hardware_concurrency()) 
    : abort_requested_{false}, stop_requested_{false}
  {
    // Avoid vector resizing itself and reserve RAM for num_threads objects...
    threads_.reserve(num_threads);

    // Create num_threads std::jthreads that run worker()...
    for (std::size_t i{}; i != num_threads; ++i)
      threads_.emplace_back(&run_parallel_tasks::worker,this);
  }

  // Prohibit copies...
  run_parallel_tasks(run_parallel_tasks const&) = delete;
  run_parallel_tasks& operator=(run_parallel_tasks const&) = delete;

  // Prohibit moves...
  run_parallel_tasks(run_parallel_tasks&&) = delete;
  run_parallel_tasks& operator=(run_parallel_tasks&&) = delete;

  ~run_parallel_tasks()
  {
    request_stop();
    for (auto& t : threads_)
      t.join();
  }

  void enqueue(std::function<void()> f)
  {
    // Define aa code block to wait, hold, and free a lock...
    {
      // Wait for a lock on m_...
      std::unique_lock<std::mutex> lock(m_);
      // Now that the lock has been acquired, enqueue op...
      q_.push(f);
    }

    // Outside the scope of the lock, notify the condition variable
    // q_'s state has been changed...
    enq_deq_cv_.notify_one();
  }

  void request_stop()
  {
    if (!stop_requested_)
    {
      stop_requested_ = true;
      enq_deq_cv_.notify_all();
    }
  }

  void request_abort()
  {
    if (!abort_requested_)
    {
      stop_requested_ = true;
      abort_requested_ = true;
      enq_deq_cv_.notify_all();
    }
  }
};

//===========================================================================

#endif // #ifndef comp3400_2020w_run_parallel_tasks_hpp_
