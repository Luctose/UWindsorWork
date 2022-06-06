#include <string>
#include <iostream>

using namespace std;

template <typename Char>
struct foo
{
  basic_string<Char> data_;
};

template <typename Char, typename CharTraits>
std::basic_ostream<Char,CharTraits>& operator<<(std::basic_ostream<Char,CharTraits>& os, foo<Char> const& f)
{
  os << f.data_;
  return os;
}

int main()
{
  foo<char> f{"abcdef"};
  cout << f << '\n';
}

