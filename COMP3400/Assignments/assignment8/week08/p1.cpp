#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>

int main()
{
  namespace fs = std::filesystem;

  try
  {
    fs::directory_iterator di(".");
    for (auto const& direntry : di)
      std::cout << direntry.path() << '\n';
  }
  catch (std::exception const& e)
  {
    std::cerr << "EXCEPTION: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
