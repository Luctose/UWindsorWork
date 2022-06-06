#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <exception>
#include <filesystem>
#include <queue>
#include <list>
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

  uintmax_t total_size{};

  queue<fs::path> q;
  try
  {
    q.emplace(argv[1]); // i.e., q.push( fs::path{argv[1]} );
                       
    while (!q.empty())
    {
      fs::directory_iterator di(q.front());
      q.pop();

      for (auto const& direntry : di)
      {
        if (is_directory(direntry) && !is_symlink(direntry))
          q.push(direntry.path());
        else if (is_regular_file(direntry))
        {
          total_size += file_size(direntry);
          cout << direntry.path() << '\n';
        }
      }
    }

    cout << "Total size of all files: " << total_size << '\n';
  }
  catch (std::exception const& e)
  {
    std::cerr << "EXCEPTION: " << e.what() << '\n';
  }
  return EXIT_SUCCESS;
}
