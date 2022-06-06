#include <cmath>
#include <future>
#include <iostream>

using namespace std;

void task1()
{
  // we want a task/function that will accept a float and return a float...
  packaged_task<float(float)> task(
    [](float f) { return std::cos(f); }
  );

  // get the "future" result of having called task...
  future<float> result = task.get_future();

  // ...
  task(2.42F); // call task :-)
  // ...

  cout << "task1's result: " << result.get() << '\n';
}


int main()
{
  task1();
}
