// NOTE: This code uses underlying_type_t so at least -std=c++14 is needed to
//       compile this code.

#include <iostream>
#include <type_traits>

enum class eg1 : short { a=-5, b, c=1, d, e };

std::ostream& operator<<(std::ostream& os, eg1 const& value)
{
  os << 
    static_cast< // i.e., cast value to the eg1 integer type
      std::underlying_type_t<eg1> // i.e., get the type of integer used in the eg1 enum
    >(value)
  ;
  return os;
}

// enum class semester { fall, winter, summer };

int main()
{
  std::cout 
    << eg1::a << ' '
    << eg1::b << ' '
    << eg1::c << ' '
    << eg1::d << ' '
    << eg1::e << '\n'
  ;
}

