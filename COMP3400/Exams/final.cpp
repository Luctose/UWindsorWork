/*
 * Final Exam Question
 * COMP-3400
 * Winter 2022
 * By: Lucas Sarweh
 * ID: 110042658
 * April 20th 2022
 */

#include <iostream>
#include <vector>
#include <optional>
#include <map>
#include <cmath>
#include <algorithm>

// Output optional<T> to an output stream
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt){
    // Check if the opt has a value
    if(opt.has_value()){
        // Output value to ostream
        os << opt.value();
    }
    // Return ostream
    return os;
}

// Output vector<T> to an output stream
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec){
    // Make sure vector is not empty
    if(!vec.empty()){
        // For each vector element
        for(const auto& i : vec){
            // Output the current element followed by a space
            os << i << ' ';
        }
    }
    // Return output stream
    return os;
}

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, const std::map<Key, Value>& mymap){
    // Output opening brace
    os << "{ ";
    // Loop through the map
    for(const auto& [k, v] : mymap){
        // Output depending on condition
        if(v == 1){
            os << k << ' ';
        }else{
            os << k << '^' << v << ' ';
        }
    }
    // Output closing brace
    os << '}';
    // Return output stream
    return os;
}

std::vector<std::uintmax_t> primes_via_trial_division(std::uintmax_t const& n){
    std::vector<std::uintmax_t> primes;
    for(std::uintmax_t i = 2; i < n; ++i){
        if(std::all_of(begin(primes), end(primes),
            [&](const auto& prime_number) -> bool{
                if(i % prime_number != 0){
                    return true;
                }
                // Return false otherwise
                return false;
            }
            )
        ){
            // Add i to the primes
            primes.push_back(i);
        }
    }
    // Return primes vector
    return primes;
}

std::optional<std::map<uintmax_t, size_t>> prime_factors_via_trial_division(
    uintmax_t const& n,
    std::vector<uintmax_t> const& primes
){
    // Define a map for returning
    std::map<uintmax_t, size_t> factors;
    // No primes
    if(primes.empty()){
        // optional no value
        return std::nullopt;
    }
    uintmax_t mysqrt = std::sqrt(n);
    // Largest prime < floor(sqrt(n))
    if(primes.back() < mysqrt){
        // optional no value
        return std::nullopt;
    }
    uintmax_t left_over = n;
    auto primesEnd = std::upper_bound(begin(primes), end(primes), mysqrt);

    std::for_each(begin(primes), end(primes),
    [&](const auto& prime){
        size_t exp = 1;
        while(left_over % prime == 0){
            left_over = left_over / prime;
            factors.insert_or_assign(prime, exp);
            ++exp;
        }
    }
    );
    size_t exp = 1;
    if(left_over != 1){
        factors.insert_or_assign(left_over, exp++);
    }
    return factors;
}

int main()
{
    using namespace std;
#if 0
    if(uintmax_t max_number; cin >> max_number)
    {
        auto const primes = primes_via_trial_division(max_number);

        using size_type = decltype(primes)::size_type;

        cout
            << "There are " << primes.size() << " primes bewteen 0 and "
            << max_number << '\n'
            << "The first 15 primes are: "
        ;
        // WRITE FIRST STD::COPY CALL HERE!
        std::copy(begin(primes), min(primes.size(), size_t {15} == primes.size ? end(primes) : begin(primes) - 15),
        ostream_iterator<uintmax_t>(std::cout, " ")
        );
        cout << "\nThe last 15 primes are: ";
        // WRITE SECOND STD::COPY CALL HERE!
        std::copy(min(primes.size(), size_t {15}) ? begin(primes) : begin(primes) + primes.size(), end(primes),
        ostream_iterator<uintmax_t>(std::cout, " ");
        cout << '\n';
        
        for(uintmax_t i; cin >> i; )
        {
            auto const prime_factors = prime_factors_via_trial_division(i, primes);
            cout << "factors(" << i << "): ";
            if(prime_factors)
                cout << prime_factors;
            else
                cout << "unable to compute from calculated primes";
            cout << '\n';
        }
    }
#endif
}


