#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void output(T& object)
{
  cout << "There are " << object.size() << " elements.\n";
  for (int const& i : object)
    cout << i << ' ';
  cout << '\n';
}

int main()
{
  vector<int> v;

  for (int i; cin >> i; )
    v.push_back(i);

  vector<int> v2;
  transform(
    begin(v), end(v), // input "range", i.e., [begin,end)
    back_inserter(v2), // start of the output
    [](int const& value)
    {
      return value*2;
    }
  );

  output(v);
  output(v2);
}
