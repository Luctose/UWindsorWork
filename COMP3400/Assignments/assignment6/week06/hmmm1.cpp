#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
T middle_value(T const& a, T const& b, T const& c)
{
  using namespace std;
  vector<T> v{ a, b, c };
  nth_element(begin(v), begin(v)+1, end(v));
  return v[1];
}

int main()
{
  std::cout << middle_value(-5, -100, 78) << '\n';
}
