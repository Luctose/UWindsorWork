#include <iostream>
#include <cmath>

using namespace std;

double eg1(double d)
{
  return d+1.0;
}

double eg2(double d)
{
  return sin(d);
}

double eg3(double d)
{
  return cos(d);
}

template <typename Func>
void output(Func f)
{
  cout << f(3.2) << '\n';
}

int main()
{
  output(eg1);
  output(eg2);
  output(eg3);
}
