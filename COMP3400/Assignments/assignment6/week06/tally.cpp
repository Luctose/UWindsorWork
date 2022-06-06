#include <iostream>

#include "tally.hpp"

int main()
{
  using namespace std;

  tally t;
  cout << t << '\n';

  t += 1.0; cout << t << '\n';
  t += 2.0; cout << t << '\n';
  t += 3.0; cout << t << '\n';
}
