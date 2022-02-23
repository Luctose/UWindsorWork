#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<string> v;

#if 0
  for (string s; cin >> s;)
    v.push_back(move(s));
#else
  copy(
    istream_iterator<string>(cin), istream_iterator<string>(),
    back_inserter(v)
  );
#endif

  //sort(begin(v), end(v), less<string>{});
  sort(begin(v), end(v), greater<string>{});

  copy(begin(v), end(v), ostream_iterator<string>(cout, " "));
}
