#include <iostream>

struct fun { };

int main()
{
  try
  {
    throw fun{};
    //throw 45;
  }
  catch (fun& f)
  {
    std::cout << "Exception(fun): " << &f << '\n';
  }
  catch (int& ex)
  {
    std::cout << "Exception(int): " << ex << '\n';
  }
  catch (...)
  {
    std::cout << "Unknown exception caught.\n";
  }
}

