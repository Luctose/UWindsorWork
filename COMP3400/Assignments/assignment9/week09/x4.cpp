#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  string a = "Hello";
  vector<char> b(a.begin(), a.end());
  string c(b.begin(), b.end());

  cout << a.data() << '\n'; // works in C++11 on; before C++11 this likely crashed
  cout << a.c_str() << '\n'; // works in all C++ since C++98
}
