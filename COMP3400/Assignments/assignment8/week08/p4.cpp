#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>

int main(int argc, char *argv[])
{
  using namespace std;
  namespace fs = std::filesystem;

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <path>\n";
    return EXIT_FAILURE;
  }

  bool done = false;
  do 
  {
    try
    {
      fs::path root{argv[1]}; // where we start processing

      fs::recursive_directory_iterator di(root);
      for (auto const& direntry : di)
      {
        bool isdir = is_directory(direntry);
        bool isfile = is_regular_file(direntry);
        std::cout << isdir << ' ' << isfile << ' ' << direntry.path() << '\n';
      }
      done = true;
    }
    catch (std::exception const& e)
    {
      std::cerr << "EXCEPTION: " << e.what() << '\n';
    }
  }
  while (!done);
  return EXIT_SUCCESS;
}
