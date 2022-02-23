#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

// input iterator
// forward iterator (e.g., singly-linked list, doubly-linked list, vector, deque)
// bidirectional iterator (e.g., doubly-linked list, vector, deque)
// random-access iterator (e.g., vector)
// output iterator

template <typename InputIter, typename OutputIter>
void mycopy(InputIter first, InputIter last, OutputIter out)
{
  for (; first != last; ++first)
  {
    *out = *first;
    ++out;
  }
}

template <typename InputIter, typename OutputIter, typename Func>
void mytransform(InputIter first, InputIter last, OutputIter out, Func f)
{
  for (; first != last; ++first)
  {
    *out = f( *first );
    ++out;
  }
}

int main()
{
  vector<int> v;

#if 0
  for (int s; cin >> s;)
    v.push_back(move(s));
#else
  mycopy(
    istream_iterator<int>(cin), istream_iterator<int>(),
    back_inserter(v)
  );
#endif

  //sort(begin(v), end(v), less<int>{});
  sort(begin(v), end(v), greater<int>{});

  mytransform(
    begin(v), end(v),
    begin(v),
    [](auto const& value)
    {
      return value*10;
    }
  );

  mycopy(begin(v), end(v), ostream_iterator<int>(cout, " "));
}
