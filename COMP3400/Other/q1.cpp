#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> v;

  for (int i; cin >> i; )
    v.push_back(i);

  for (int const& i : v)
    cout << i << ' ';
  cout << '\n';
}
