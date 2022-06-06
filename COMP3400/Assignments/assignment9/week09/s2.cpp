#include <string>
#include <sstream>
#include <locale>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " number\n";
    return 1;
  }

  istringstream bufstream(argv[1]);
  bufstream.imbue(locale("de_DE"));
  double d;
  int i;
  if (bufstream >> d)
  {
    cout << "Read in: " << d << '\n';
  }
  else 
    cout << "Uh oh!\n";
}



