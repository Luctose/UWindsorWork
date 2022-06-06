/*
 * Assignment 9
 * COMP-3400
 * University of Windsor
 * March 29 2022
 * By: Lucas Sarweh
 * ID: 110042658
 */

#include <exception>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <filesystem>
#include <regex>

int main(int argc, char **argv){
    try{
        // Check commadn line argc
        if(argc != 3){
            std::cerr << "Usage: " << argv[0] << " datadir filename-regex\n";
            return EXIT_FAILURE;
        }
        // Make path to check if arg 1 is a directory
        std::filesystem::path p{argv[1]};
        std::error_code code;
        if(std::filesystem::is_directory(p, code) == false){
            std::cerr << "ERROR: " << argv[1] << " is not a directory.\n";
            return EXIT_FAILURE;
	    }
	    // Make a proximate path to the current dir
	    std::filesystem::path pp{std::filesystem::proximate(p, code)};
	    // Compare to make sure the proximate path is less
	    if(pp.string().size() < p.string().size()){
	        // Use the proximate version
            	std::cout << "Processing: " << pp.string() << '\n';
            	p = pp;
	    }else{
            	// Use original version
            	std::cout << "Processing: " << p.string() << '\n';
	    }
        // Construct given regex
        std::regex myregex{argv[2]};
	// Make iterator
	std::filesystem::recursive_directory_iterator diriter{p};
        // Go through the dir's
        std::for_each(begin(diriter), end(diriter),
        [&](const auto &entry){
            if(std::filesystem::is_regular_file(entry) && std::regex_match(entry.path().filename().string(), myregex)){
                // Output the matched filed
                std::cout << "Match: " << entry.path() << '\n';
            }
        }
        );
        // No errors return success
        return EXIT_SUCCESS;
    }catch(const std::exception& e){
        std::cerr << "EXCEPTION: " << e.what() << '\n';
        // Error caught return failure
        return EXIT_FAILURE;
    }catch(...){
        std::cerr << "FATAL: Unknown expception occurred.\n";
        // Worse error caught
        return EXIT_FAILURE;
    }
}
