#include <iostream>

struct fun { };

void more_fun()
{
  throw fun{};
}

void even_more_fun()
{
  more_fun();
}

int main()
{
  try
  {
    even_more_fun();
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

