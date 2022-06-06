
#include <iostream>
#include "benchmark.hpp"

void foo()
{
  // whatever
}

int bar()
{
  return 5;
}

int silly(int i)
{
  return i*3;
}

[[nodiscard]] int silly2(double d, int i)
{
  return d+i;
}

int main()
{
  std::cout 
    << simple_benchmark(3, foo) << '\n'
    << simple_benchmark(3, bar) << '\n'
    << simple_benchmark(3, silly, 67) << '\n'
    << simple_benchmark(3, silly2, 1.1, -2) << '\n'
  ;
}


