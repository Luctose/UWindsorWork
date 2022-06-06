#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main()
{
  // . means any character
  // * means zero or more of the previous character
  // <.*> means look for '<' followed by any number of characters (0 or more), followed by '>'
  regex re("<.*>.*</.*>");
  if (regex_match("<h1>Heading</h1>", re))
    cout << "We found a match!\n";
  else
    cout << "No match found!\n";
}

