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

int main()
{
  cout << "Type in 1, 2, or 3: ";
  int i;
  if (cin >> i)
  {
    double (*funcptr)(double) = nullptr;

    switch (i)
    {
      default:
      case 1: funcptr = eg1; break;
      case 2: funcptr = eg2; break;
      case 3: funcptr = eg3; break;
    }

    cout << "The result is: " << funcptr(2.2) << '\n';
  }
  else
    cout << "Invalid value entered.\n";
}
