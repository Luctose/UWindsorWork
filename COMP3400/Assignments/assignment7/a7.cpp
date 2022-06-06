/*
Assignment 7
COMP-3400
University of Windsor
March 19 2022
By: Lucas Sarweh
ID: 110042658
*/

#include <algorithm>
#include <execution>
#include <limits>
#include <random>
#include <vector>
#include <sstream>
#include <iostream>
#include "benchmark.hpp"
#include "utils.hpp"

constexpr bool is_prime_trial_division(unsigned const& n)
{
    using std::sqrt;

    if(n < 2)
        return false;

    auto const sqrt_n = isqrt(n);
    bool retval = true;
    for(unsigned i = 2; i <= sqrt_n && retval; ++i)
        retval &= (n % i != 0);
    return retval;
}

template <typename ExecPolicy, typename Container>
auto do_work(ExecPolicy& ep, Container const& v){
    auto res = results_benchmark(3, 
    [&](){
        return count_if(ep, begin(v), end(v), is_prime_trial_division);
    }
    );
    std::cout << "\ttime: " << res.time << " seconds\n";
    std::cout << "\tresults: ";
    for(auto i : res.results){
        std::cout << i << " ";
    }
    std::cout << "\n";
    return res;
}

int main(int argc, char **argv){
	unsigned N = 30;
    std::random_device::result_type SEED;
    // User wrong args
    if(argc != 3){
        std::cerr << "Usage: " << argv[0] << " <number-of-integers> <random_seed>\n";
        return 1;
    }
    std::istringstream buf(argv[1]);
    if(unsigned tmp; buf >> tmp)
        N = tmp;
    else{
        std::cerr << "Invalid integer value.\n";
    return 2;
    }

    std::istringstream buf2(argv[2]);
    if(std::random_device::result_type tmp; buf2 >> tmp)
        SEED = tmp;
    else{
        std::cerr << "Invalid random seed.\n";
        return 3;
    }

    std::default_random_engine re(SEED);
    std::uniform_int_distribution<unsigned> ud(2, std::numeric_limits<unsigned>::max());

    std::vector<unsigned> myvec;
    myvec.reserve(N);
    std::generate_n(std::back_inserter(myvec), N,
    [&](){
        return ud(re);
    }
    );

    std::cout << "sequential results:\n";
    auto resultseq = do_work(std::execution::seq, myvec);

    std::cout << "parallel results:\n";
    auto resultpar = do_work(std::execution::par, myvec);

    std::cout << "conclusion: ";
    if((resultseq.time.mean() + (3 * resultseq.time.stddev()))
    	< resultpar.time.mean()){
	std::cout << "compute the results sequentially\n";
    }else{
        std::cout << "compute the results in parallel\n";
    }
}
