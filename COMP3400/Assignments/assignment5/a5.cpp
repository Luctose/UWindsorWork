/*
Assignment 5
COMP-3400
University of Windsor
February 19 2022
By: Lucas Sarweh
ID: 110042658
*/

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstddef>

// Cycle sort algorithm
template <typename Iter, typename CompareFunc>
std::size_t cycle_sort(Iter const& first, Iter const& last, CompareFunc const& cmp){
    // Track number of writes
    std::size_t writes = 0;
    // Check if it's empty
    if(first == last){
        // Zero writes
        return writes;
    }
    
    // Iterate through structure
    for(Iter start = first; start != std::prev(last); ++start){
        // Track the current item we want to place
        auto item = *start;
        // Track the items rightful index
        auto pos = start;

        // Find the index for pos of the current item
        for(auto i = std::next(start); i != last; ++i){
            if(cmp(*i, item)){ // Use passed in function for comparisons
                // Add to the position everytime we get a true comparison
                ++pos;
            }
        }
        // Item was already in the right place as pos didn't move
        if(pos == start){
            /* Is using this bad? It says it on the wikipedia page,
            but I remember (vaguely) seeing somewhere it's better to not continue
            */
            continue; // Restart and make next element the starting place
        }

        // Skip over duplicates
        while(item == *pos){
            ++pos;
        }

        // Swap the item with the item currently in it's spot
        std::swap(*pos, item);
        ++writes; // We wrote to the structure so add to writes

        // Rotate the rest of the cycle
        while(pos != start){
            // Start pos at the start
            pos = start;
            // Find the proper position of the item
            for(auto i = std::next(start); i != last; ++i){
                if(cmp(*i, item)){ // Use given compare function
                    ++pos;
                }
            }
            // Skip any duplicates
            while(item == *pos){
                ++pos;
            }
            // Swap the item with the item currently in it's spot
            std::swap(*pos, item);
            ++writes;
        }
    }

    // Return total writes when done
    return writes;
}

// Execution starts here
int main(int argc, char **argv){
    // Case if no command line args are passed
    if(argc < 2){
        // Output to standard error
        std::cerr << "Usage: " << argv[0] << " <input_file>\n"
        << "ERROR: Missing filename.\n";
        // Exit code 1
        return 1;
    }
    else if(argc > 2){ // Too many command line args are passed
        // Output to standard error
        std::cerr << "Usage: " << argv[0] << " <input_file>\n"
        << "ERROR: Too many arguments.\n";
        // Exit code 2
        return 2;
    }
    // No arg problems, run the program

    // Open filename from argv for reading (input by default)
    std::ifstream in(argv[1]);
    // Make sure it opened
    if(!in.is_open()){ // Error
        // Output to standard error
        std::cerr << "ERROR: File " << argv[1] << " could not be opened.\n";
        // Exit code 1
        return 1;
    }
    // Create list object
    std::list<int> l;

    // Insert the ints from the input file into the back of l
    std::copy(std::istream_iterator<int>(in), std::istream_iterator<int>(),
    std::back_inserter(l));

    // Output read data
    std::cout << "Original data: ";
    std::copy(std::begin(l), std::end(l), 
    std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    // Required call to calling cycle sort given
    auto w = cycle_sort(begin(l), end(l), std::less<>{});
    // Number of writes to cout
    std::cout << "num_writes: " << w << "\n";

    // Write sorted data to cout
    std::cout << "sorted_data: ";
    copy(std::begin(l), std::end(l),
    std::ostream_iterator<int>(std::cout, " "));

    // Program ran successfully
    return 0;
}