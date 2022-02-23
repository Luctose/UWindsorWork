#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> v;

  for (int i; cin >> i; )
    v.push_back(i);

#if 0
  for (int i=0; i != v.size(); ++i)
    v[i] *= 2;
#else
  transform(
    begin(v), end(v), // input "range", i.e., [begin,end)
    begin(v),         // start of the output
    [](int const& value)
    {
      return value*2;
    }
  );
#endif

  cout << "There are " << v.size() << " elements in v.\n";
  for (int const& i : v)
    cout << i << ' ';
  cout << '\n';
}
