#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>

using namespace std;

constexpr int N = 10'000'000;

int main()
{
  random_device rd;
  default_random_engine re( rd() );
  uniform_int_distribution<int> ud(5,100);

  vector<int> v(N);

  auto t0 = chrono::steady_clock::now();
  generate_n(begin(v), N, [&]() { return ud(re); });
  auto t1 = chrono::steady_clock::now();
  sort(begin(v), end(v));
  auto t2 = chrono::steady_clock::now();
  cout << "timeA: " << chrono::duration<double>(t1-t0).count() << " seconds\n";
  cout << "timeB: " << chrono::duration<double>(t2-t1).count() << " seconds\n";
}
