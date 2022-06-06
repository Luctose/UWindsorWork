//===========================================================================

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <syncstream>

#include "run_parallel_tasks.hpp"

//===========================================================================

constexpr auto MIN_NUM_DIRS_OR_FILES = 5;
constexpr auto MAX_NUM_DIRS_OR_FILES = 8;
constexpr auto MIN_NAME_LEN = 10;
constexpr auto MAX_NAME_LEN = 20;
constexpr auto MIN_NUMS_PER_FILE = 10'000;
constexpr auto MAX_NUMS_PER_FILE = 90'999;

//===========================================================================

std::filesystem::path filename_with_up_to_n_parents(
  std::filesystem::path p, 
  std::size_t nparents
)
{
  if (!p.has_filename())
    return {};

  std::filesystem::path retval(p.filename());
  for (
    ; 
    nparents != 0 && p.has_parent_path();
    --nparents
  )
  {
    p = p.parent_path();
    retval = p.filename() / retval;
  }
  return retval;
}

//===========================================================================

std::string generate_random_name()
{
  using namespace std;
  using namespace std::literals;

  //
  // Define some thread_local static variables inside this function
  // since the <random> API is not thread safe. (In effect this creates
  // different random engines on each independent thread.)
  //
  static thread_local default_random_engine 
    char_re(random_device{}()),
    len_re(random_device{}())
  ;

  // Define the valid chars that can appear in a name...
  //   * This isn't thread-local since it is read-only.
  static string const valid_chars{
    "0123456789_@$#%abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"s
  };

  // Define a distribution that spans over valid_chars...
  static thread_local uniform_int_distribution<string::size_type> char_dist{ 
    0, valid_chars.size()-1 
  };

  // Define a distribution for the file name lengths...
  static thread_local uniform_int_distribution<string::size_type> len_dist{
    MIN_NAME_LEN, MAX_NAME_LEN };

  // Get a random file name length...
  auto const len = len_dist(len_re);

  string retval;
  retval.reserve(len);  // reserve the RAM for fname of len size
  generate_n(           // generate a random file name of length len
    back_inserter(retval),
    len,
    [&]() { return valid_chars[char_dist(char_re)]; }
  );
  return retval;
}

//===========================================================================

void generate_file(std::filesystem::path const& fpath)
{
  using namespace std;

  //
  // Define thread local random devices and engines since the <random> API
  // is not thread-safe. (All use of such is completely contained inside
  // each invocation of this function.)
  //
  static thread_local random_device rd;
  static thread_local default_random_engine re(rd());

  uniform_int_distribution<unsigned> num_dist{
    MIN_NUMS_PER_FILE, MAX_NUMS_PER_FILE};
  uniform_real_distribution<float> real_udist{-1.0F,1.0F};

  // For each file, generate a random name and write out
  // a random number of random float values to that file...
  auto const num_values = num_dist(re);
  auto newfname = generate_random_name();

  ofstream out(fpath);
  generate_n(
    ostream_iterator<float>(out, " "),
    num_values,
    [&]() { return real_udist(re); }
  );

  // C++20 instroduced std::syncstream to avoid having to write code
  // using std::mutex to synchronize output across threads writing
  // to the same stream.
  osyncstream(clog)
    << "wrote " << num_values << " values in " << fpath << '\n'
  ;
}

//===========================================================================

void generate_data(
  std::filesystem::path datadir, 
  std::size_t const& nthreads = std::thread::hardware_concurrency()
)
{
  using namespace std;
  namespace fs = std::filesystem;

  run_parallel_tasks rpt(max(nthreads,decltype(nthreads){1}));

  // Compute the data directory path RELATIVE to curdir...
  auto curdir = fs::current_path();
  if (std::error_code ec; fs::equivalent(curdir,datadir,ec))
    // curdir and datadir refer to the same object!
    throw runtime_error("Cannot use the current directory as datadir!\n");

  // Purge datadir if it already exists...
  // ASIDE: Normally in applications one would not remove data
  //        without prompting the user first. This code demonstrates
  //        how one can recursively remove a directory.
  if (is_directory(datadir))
  {
    clog << "Removing previous datadir: " << datadir << '\n';
    remove_all(datadir);
    clog << "Finished removing previous datadir.\n";
  }

  // Create an empty datadir...
  create_directory(datadir);
  clog << "Created directory: " << datadir << '\n';
 
  // declare some variables for random numbers...
  random_device rd;
  default_random_engine re(rd());
  uniform_int_distribution<unsigned> num_dist(
    MIN_NUM_DIRS_OR_FILES, MAX_NUM_DIRS_OR_FILES);

  // Choose a random number of directories to create...
  auto const num_dirs = num_dist(re); 
  clog << "# of directories: " << num_dirs << '\n';

  for (unsigned i{}; i != num_dirs; ++i)
  {
    // Generate a random name and create a path to such
    // to allow creating such as a directory...
    auto newdir = datadir / generate_random_name();
    create_directory(newdir);

    // Choose a random nuymber of files to create...
    unsigned const num_files = num_dist(re);
    clog << "# of random files " << num_files 
      << " in " << newdir << '\n';

#if 0
    //
    // If one wanted to use a function object instead of
    // a lambda below. If so, replace the rpt.enqueue()
    // call line with:
    //   rpt.enqueue(myfunc{newfile});
    //
    struct myfunc
    {
      fs::path fpath;
      void operator()() const
      {
        generate_file(fpath);
      }
    };
#endif

    for (unsigned j{}; j != num_files; ++j)
    {
      auto newfile = newdir / generate_random_name();
      // IMPORTANT: One must capture newfile by value, i.e.,
      //            make a copy since it will be running in
      //            another thread and this for loop creates
      //            work for many threads using variables
      //            with the same addresss. Don't capture by
      //            reference.
      rpt.enqueue([=](){ return generate_file(newfile); });
    }
  }
}

//===========================================================================

int main(int argc, char *argv[])
{
  using namespace std;

  try
  {
    if (argc < 2 || argc > 3)
    {
      cerr 
        << "Usage: " << argv[0] << " datadir [num_threads]\n"
           "       Warning: Original datadir will be REMOVED!\n"
      ;
      return EXIT_FAILURE;
    }
    else if (argc == 2)
      generate_data(argv[1]);
    else //if (argc == 3)
    {
      using hwconcurrency_type = decltype(thread::hardware_concurrency());

      istringstream buf(argv[2]);
      if (hwconcurrency_type n; buf >> n && n > 0 && 
        n <= thread::hardware_concurrency())
        generate_data(argv[1],n);
      else
      {
        cerr << "ERROR: Invalid number of threads specified.\n";
        return EXIT_FAILURE;
      }
    }
  }
  catch (std::exception const& e)
  {
    cerr << "EXCEPTION: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  catch (...)
  {
    cerr << "UNKNOWN_EXCEPTION: Aborting.\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

//===========================================================================
