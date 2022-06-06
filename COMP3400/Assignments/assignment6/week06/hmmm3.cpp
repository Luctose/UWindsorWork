#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

template <typename T, typename Compare = std::less<T> >
T middle_value(T const& a, T const& b, T const& c, Compare cmp = {})
{
  using namespace std;
  array<T,3> v{ a, b, c };
  nth_element(begin(v), begin(v)+1, end(v), cmp);
  return v[1];
}

int main()
{
  std::cout << middle_value(-5, -100, 78) << '\n';
  std::cout << middle_value(
    -200, 78, -50,
    [](auto const& a, auto const& b) 
    {
      return a < b;
    }
  ) << '\n';
}
