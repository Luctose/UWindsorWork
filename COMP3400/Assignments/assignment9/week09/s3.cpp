#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  ofstream out("test.dat", ios::binary);
  out << 32132.23 << '\n'; // formatted (output)
                          
  out.put('\0');           // unformatted (output) ~equivalent to fputc
                           
  double d = 3.141592;
  out.write(
    reinterpret_cast<char const*>(&d), 
    sizeof(d)
  ); // unformatted (output) ~equivalent to fwrite
}

