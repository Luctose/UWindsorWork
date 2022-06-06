/*
Assignment 6
COMP-3400
University of Windsor
March 14 2022
By: Lucas Sarweh
ID: 110042658
*/

#include <random>
#include <iostream>
#include <sstream>
#include <list>
#include <set>
#include <array>
#include <algorithm>
#include <iterator>

int main(int argc, char **argv){
    std::random_device rd;
    std::random_device::result_type SEED = rd(); // random default seed

    if(argc > 2){ // To many arguments from command line
        std::cerr << "Usage: " << argv[0] << " [<random_seed>]\n";
        return 1; // Minor error
    }
    else if(argc == 2){
        std::istringstream buf(argv[1]);
        if (std::random_device::result_type tmp; buf >> tmp)
            SEED = tmp;
        else
        {  
            std::cerr << "Invalid random seed.\n";
            return 2;
        }
    }
    // Output the seed
    std::cout << "SEED: " << SEED << "\n";

    std::default_random_engine re(SEED);
    std::uniform_int_distribution<int> ud(-9,9);

    std::list<int> mylist;

    // Populate list with uniform distributed ints
    std::generate_n(std::back_inserter(mylist), 30, 
    [&]() -> int{
        return ud(re);
    });

    // Output random numbers
    std::cout << "original values: ";
    std::copy(std::begin(mylist), std::end(mylist),
    std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n"; // Newline

    // Declare vector of iterators
    std::vector<std::list<int>::iterator> ivec;

    // Populate vector with mylist iterators
    for(auto i = begin(mylist); i != end(mylist); ++i){
        ivec.push_back(i);
    }
    // Make a copy of the vector
    auto vcopy = ivec;
    // Sort the data
    std::sort(begin(vcopy), end(vcopy),
    [](const auto& a, const auto& b){
        return *a < *b;
    }
    );

    // Output sorted values
    std::cout << "sorted values:";
    std::for_each(begin(vcopy), end(vcopy),
    [](const auto &a){
        std::cout << " " << *a;
    }
    );
    std::cout << "\n";
    
    // Get lambda type
    auto It_op = [](const auto& a, const auto& b) -> bool{ return *a < *b; };
    
    // Make type alias for the set type I'm using
    using myset = std::set<std::list<int>::const_iterator, decltype(It_op)>;
    // Make array of 4 of these sets
    std::array<myset, 4> four_sets;
    
    // Count
    std::size_t count;
    // Beggining of vector of iterators
    auto i = begin(ivec);
    
    // Give the values the iterators refer to to the 4 sets like dealing cards
    for(count = 0; count != 5; ++count){
        for(int j = 0; j != 4 && i != end(ivec); ++j, ++i){
            four_sets[j].insert(*i);
        }
    }
    // Erase vector elements up to i
    ivec.erase(begin(ivec), i);
    

    // Output ivec
    std::cout << "remaining values:";
    std::for_each(begin(ivec), end(ivec), 
    [](const auto &a){
        std::cout << " " << *a;
    }
    );
    std::cout << "\n";

    // Output the sets iterators
    for(int j = 0; j != 4; ++j){
        std::cout << "player " << (j + 1) << " has";
        std::for_each(begin(four_sets[j]), end(four_sets[j]),
        [](const auto &a){
            std::cout << " " << *a;
        }
        );
	std::cout << "\n";
    }
}
