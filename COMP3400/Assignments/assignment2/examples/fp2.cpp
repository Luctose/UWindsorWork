#include <cstdio>
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
  printf("Type in 1, 2, or 3: ");
  int i;
  if (scanf("%d",&i) == 1)
  {
    double (*funcptr)(double) = NULL;

    switch (i)
    {
      default:
      case 1: funcptr = eg1; break;
      case 2: funcptr = eg2; break;
      case 3: funcptr = eg3; break;
    }

    printf("The result is: %lf\n", funcptr(2.2));
  }
  else
    printf("Invalid value entered.\n");
}
