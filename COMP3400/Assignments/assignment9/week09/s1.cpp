#include <string>
#include <sstream>
#include <locale>
#include <iostream>

using namespace std;

int main()
{
  char const* simple_str = "1.000,023 1.021";
  
  istringstream bufstream(simple_str);
  bufstream.imbue(locale("de_DE"));
  double d;
  int i;
  if (bufstream >> d >> i)
    cout << "Read in: " << d << ' ' << i << '\n';
  else 
    cout << "Uh oh!\n";
}



