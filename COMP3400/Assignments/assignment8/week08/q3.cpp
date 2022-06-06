#include <cmath>
#include <future>
#include <mutex>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

struct foo
{
  mutable mutex vector_mutex; // mutexes cannot be const if we want to lock on it
  vector<double> v;

  foo() = default;

  foo(foo const& f)
  {
    lock_guard lk(f.vector_mutex); // once acquired this gives us exclusive access to f.v
    v = f.v; // free to copy
  }

  foo& operator=(foo const& f)
  {
    scoped_lock slk(f.vector_mutex, this->vector_mutex); // we need both exclusively
    v = f.v;
    return *this;
  }

  double operator[](int index)
  {
    lock_guard lk(vector_mutex);
    return v[index];
  }
};


int main()
{
}
