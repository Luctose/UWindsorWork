/*
 * Assignment 10
 * COMP-3400
 * University of Windsor
 * April 5th 2022
 * By: Lucas Sarweh
 * ID: 110042658
 */

#include <random>
#include <iostream>
#include <sstream>
#include <iterator>
#include "a10_resumable_task.hpp"

std::optional<std::size_t> str_to_size_t(char const* str){
    std::istringstream mystream{str};
    std::size_t buf;
    // Attempt to read the string stream into size_t
    if(mystream >> buf){
        // Success
        return buf;
    }
    // Failure
    return std::nullopt;
}

template <typename T>
std::ostream& operator<<(std::ostream& mystream, std::vector<T> const& myvec){
    if(myvec.size() > 5){
        // Output up to first 5
        std::copy(begin(myvec), begin(myvec) + 5,
        std::ostream_iterator<T>(mystream, " ")
        );
        // Output et cetera
        std::cout << "etc.";
    }else if(myvec.size() != 0){ // Must check for empty vector as it will fault if we try to access *(end(myvec) - 1)
    	// Just output all the elements
        std::copy(begin(myvec), end(myvec) - 1,
        std::ostream_iterator<T>(mystream, " ")
        );
        // Last output w/o copy so there isn't a space at the end
        mystream << *(end(myvec) - 1);
    }
    // Return the ostream
    return mystream;
}

template <
    template <typename T> class Container,
    typename GenFunc
>
auto generate_n_each_step(std::size_t const n, GenFunc f) ->
    resumable_task<
        Container<std::decay_t<std::invoke_result_t<GenFunc>>>
    >
{
    using element_type = std::decay_t< std::invoke_result_t<GenFunc> >;
    using container_type = Container<element_type>;

    for(std::size_t i = 0; i < n; ++i){
        container_type mycontainer(n);
        std::generate_n(begin(mycontainer), n, f);
        co_yield std::move(mycontainer);
    }
}

template <typename GenFunc>
void run(std::size_t const n_runs, std::size_t const n_values, GenFunc f)
{
  using namespace std;

  auto r = generate_n_each_step<std::vector>(n_values, f);
  size_t i = n_runs;
  for (r.resume(); i != 0; --i)
  {
    cout << " run " << (n_runs - i + 1) << " |" << r.get() << "|\n";
    if (r.is_resumable())
      r.resume();
  }
}

int main(int argc, char *argv[])
{
  using namespace std;

  if (argc != 4)
  {
    cerr << "Usage: " << argv[0] << " <n> <num_uniform> <num_normal>\n";
    return EXIT_FAILURE;
  }

  auto const n = str_to_size_t(argv[1]);
  auto const n_uniform = str_to_size_t(argv[2]);
  auto const n_normal = str_to_size_t(argv[3]);

  if (!n || !n_uniform || !n_normal)
  {
    cerr << "FATAL: Invalid input.\n";
    return EXIT_FAILURE;
  }

  random_device rd;
  default_random_engine re{rd()};

  uniform_int_distribution<unsigned> ud{100,999};
  cout << "Uniform distribution:\n";
  run(*n, *n_uniform, [&]() { return ud(re); });

  uniform_real_distribution<double> nd{10.0,1.0};
  cout << "Normal distribution:\n";
  run(*n, *n_normal, [&]() { return nd(re); });

  return EXIT_SUCCESS;
}
