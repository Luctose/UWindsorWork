#include <unordered_map>
#include <string>
#include <iostream>

std::ostream& operator<<(std::ostream& os, std::pair<int,std::string> const& p)
{
  os << '<' << p.first << ',' << p.second << '>';
  return os;
}

using namespace std;

int main()
{
  // maps are dictionaries
  // a dictionary is a set of <key,value> pairs
  unordered_multimap<int,string> v{ 
    { 5, "a" }, { 23, "b" }, { -23, "c" }, { 13, "d" }, { 8, "e" }, 
    { 5, "f" }, { 23, "g" }, { -23, "h" }, { 13, "i" }, { 8, "j" }
  };

  // begin(v)   or    v.begin()

  // you can use a traditional for loop...
  //   * requires explicit iterators
  for (auto i=begin(v), iEnd=end(v); i != iEnd; ++i)
    cout << *i << ' ';
  cout << '\n';

  // you can use the "range-for loop" to go through all elements...
  //   * requires begin(CONTAINER) and end(CONTAINER) to be defined
  //     e.g., v == CONTAINTER
  for (auto const& elem : v)
    cout << elem << ' ';
  cout << '\n';
}
