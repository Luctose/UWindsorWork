#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> v{ 5, 23, -23, 13, 8 };

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
