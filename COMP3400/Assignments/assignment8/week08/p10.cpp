#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <exception>
#include <execution>
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
    uintmax_t total_size{};

    deque<fs::directory_entry> q;
    q.emplace_back( fs::path{argv[1]} );

    while (!q.empty())
    {
      auto const curdir = q.front();
      q.pop_front();

      cout << "Processing " << curdir.path() << "...\n";
      
      fs::directory_iterator dir_entries{
        curdir, fs::directory_options::skip_permission_denied
      };

      //
      // Place [begin(dir_entries),end(dir_entries)) in to a container v. Some notes:
      //
      //   * https://en.cppreference.com/w/cpp/filesystem/directory_iterator mentioned that
      //     directory_iterator is an INPUT iterator. This means that its values once 
      //     visited cannot be retrieved again.
      //
      //   * Thus, to make two passes over the dir_entries below, we will need to copy the 
      //     directory information in to a container first.
      //
      vector v(begin(dir_entries), end(dir_entries));

      // First, add all directories to q...
      copy_if(
        begin(v), end(v),
        back_inserter(q),
        [](auto const& an_entry) { return is_directory(an_entry.path()) && !is_symlink(an_entry.path()); }
      );

      // Second, total up all file sizes...
      total_size +=
        transform_reduce(
          begin(v), end(v),
          uintmax_t{},
          plus<>{},
          [](auto const& entry)
          {
            return is_regular_file(entry.path()) ? file_size(entry.path()) : uintmax_t{1};
          }
        )
      ;
    }
    cout << "Total size of all files: " << total_size << '\n';
  }
  catch (std::exception const& e)
  {
    std::cerr << "EXCEPTION: " << e.what() << '\n';
  }

  return EXIT_SUCCESS;
}
