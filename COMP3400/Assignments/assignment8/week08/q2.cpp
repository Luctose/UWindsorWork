#include <cmath>
#include <future>
#include <mutex>
#include <sstream>
#include <iostream>

using namespace std;

mutex m1; // a mutex allows locking for mutal exclusion
int i1{};

mutex m2;
int i2{};
  
mutex output_m; // mutex for cout output

void output_message(std::string const& msg)
{
  lock_guard<mutex> lk(output_m);  // acquire a lock on m, otherwise wait for the lock
  cout << msg << '\n';             // output msg
                                   // when lk goes out of scope, the lock is freed (in the destructor)
}

void process_and_output(bool b)
{
  ostringstream buf;

  {
    scoped_lock slk(m1, m2);        // waits to acquire BOTH m1 and m2 without deadlocking
    if (b) { ++i1; --i2; } else { --i1; ++i2; }
    buf << "i1: " << i1 << ", i2: " << i2 << '\n';
  }

  output_message(buf.str());
}


struct foo
{
  mutex vector_mutex;
  vector<double> v;
};


int main()
{
  auto t1 = thread(
    []() { for (unsigned i{}; i != 1'000'000; ++i) process_and_output(true); } 
  );
  auto t2 = thread(
    []() { for (unsigned i{}; i != 1'000'000; ++i) process_and_output(false); } 
  );

  t1.join();
  t2.join();
}
