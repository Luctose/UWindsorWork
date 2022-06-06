#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main()
{
  //regex re("<(.*)>.*</\\1>");
  regex re(R"(<(.*)>.*</\1>)"); // using a raw string literal R"delim(...)delim"

  if (regex_match("<h1>Heading</h1>", re))
    cout << "1 We found a match!\n";
  else
    cout << "1 No match found!\n";

  if (regex_match("<h1>Heading</dsadsda>", re))
    cout << "2 We found a match!\n";
  else
    cout << "2 No match found!\n";
}

