#include <algorithm>
#include <array>
#include <iostream>

template <typename T>
T middle_value(T const& a, T const& b, T const& c)
{
  using namespace std;
  array<T,3> v{ a, b, c };
  nth_element(begin(v), begin(v)+1, end(v));
  return v[1];
}

int main()
{
  std::cout << middle_value(-5, -100, 78) << '\n';
}
