#include <iostream>
#include <chrono>
#include <string>

template <typename Func>
void benchmark(Func f, char *path, char *filename){
    // Start time
    auto t0 = std::chrono::steady_clock::now();
    // Call the lambda function
    f(path, filename);
    // End time
    auto t1 = std::chrono::steady_clock::now();
    // Find difference in time
    auto deltatime = std::chrono::duration<double>(t1 - t0).count();
    // Output the result
    std::cout << "Benchmark took " << deltatime << " seconds\n";
}

// Execution starts here
int main(int argc, char **argv){
    // Call the benchmark
    benchmark([](char *path, char *filename)
    {// Given lambda function
        std::string pt{path};
        std::string fn{filename};
        std::string command = "java -cp " + pt + "; " + filename;
        std::system(command.c_str());
        
    },
    argv[1], argv[2]
    );
}