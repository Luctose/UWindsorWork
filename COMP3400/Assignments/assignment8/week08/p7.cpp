#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <exception>
#include <filesystem>
#include <functional> // std::plus<>
#include <numeric>
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

  try
  {
    fs::recursive_directory_iterator p{argv[1]};
    auto const total_size =
      transform_reduce(
        begin(p), end(p),
        uintmax_t{},  // base case of the reduction, i.e., 0
        plus<>{},     // reduction operator (i.e., +)
        [](auto const& entry)
        {
          return is_regular_file(entry) ? file_size(entry) : uintmax_t{};
        }
      )
    ;
    cout << "Total size of all files: " << total_size << '\n';
  }
  catch (std::exception const& e)
  {
    std::cerr << "EXCEPTION: " << e.what() << '\n';
  }

  return EXIT_SUCCESS;
}
