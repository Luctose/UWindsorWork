#include <cstdlib>
#include <locale>
#include <exception>
#include <iostream>

using namespace std;

int main()
{
  try
  {
    cin.imbue(locale::classic());

    cout.imbue(locale("de_DE"));
    //cout.imbue(locale("en_CA"));
    //cout.imbue(locale("ja_JP.UTF-8"));

    cout << "input some numbers: \n";
    for (double d; cin >> d; )
      cout << d << '\n';
  }
  catch (std::exception const& e)
  {
    cerr << "EXCEPTION: " << e.what() << "\n";
    return EXIT_FAILURE;
  }
  catch (...)
  {
    cerr << "UNKNOWN EXCEPTION OCCURRED! Aborting...\n";
    return EXIT_FAILURE;
  }
}

