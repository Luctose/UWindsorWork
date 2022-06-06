/*
 * Assignment 8
 * COMP-3400
 * University of Windsor
 * March 22 2022
 * By: Lucas Sarweh
 * ID: 110042658
 */

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <random>
#include <execution>
#include <filesystem>
#include <fstream>
#include <iostream>

struct file_info{
    std::size_t number_count;
    float sum;
};

file_info operator+(file_info const& a, file_info const& b){
    return {a.number_count + b.number_count, a.sum + b.sum};
}

file_info process_file(std::filesystem::path const& fpath){
    std::ifstream file{fpath.string()};
    file_info retval {0, 0};
    float buf;
    // While there is input to process
    while(file >> buf){
    	file_info buffer{1, buf};
	    retval = retval + buffer;
    }
    // Done return file_info structure
    return retval;
}

int main(int argc, char** argv){
    // Validate command line args
    if(argc != 2){
        std::cerr << "Usage: " << argv[0] << " datadir\n";
        return EXIT_FAILURE;
    }
    std::filesystem::path p{argv[1]};
    std::error_code code;
    if(std::filesystem::is_directory(p, code) == false){
        std::cerr << "ERROR: " << argv[1] << " is not a directory.\n";
        return EXIT_FAILURE;
    }
    // Initialize directory iterator
    std::filesystem::recursive_directory_iterator diriter{p};
    std::vector dirvec(begin(diriter), end(diriter));
    file_info myfi{0, 0.0F};
    auto result = std::transform_reduce(std::execution::par, begin(dirvec), end(dirvec),
                         myfi, std::plus<>{},
                         [&](auto const& entry){
                            return process_file(entry.path());
                         }
                         );
    // Print results
    std::cout << "total_count: " << result.number_count << '\n';
    std::cout << "total_sum: " << result.sum << '\n';

    return EXIT_SUCCESS;
}
