/*
Assignment 3
COMP-3400
University of Windsor
February 07 2022
By: Lucas Sarweh
ID: 110042658
*/

#include <iostream>
#include <chrono>

template <typename Func>
void benchmark(Func f){
    // Start time
    auto t0 = std::chrono::steady_clock::now();
    // Call the lambda function
    f();
    // End time
    auto t1 = std::chrono::steady_clock::now();
    // Find difference in time
    auto deltatime = std::chrono::duration<double>(t1 - t0).count();
    // Output the result
    std::cout << "Benchmark took " << deltatime << " seconds\n";
}

// Execution starts here
int main(){
    // Call the benchmark
    benchmark([]()
    {// Given lambda function
        int count = 0;
        for (double d; std::cin >> d; ++count)
            ;
        std::cout << count << " double values were read in.\n";
    }
    );
}