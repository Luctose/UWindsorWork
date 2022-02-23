/*
Assignment 4
COMP-3400
University of Windsor
February 15 2022
By: Lucas Sarweh
ID: 110042658
*/

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

// Record stores some info about someone
struct record{
    std::string name; // Their name
    int id; // Identifier
    double amount; // Amount
};

// Define >> for record struct
std::istream& operator>>(std::istream& is, record& rcd){
    // Temp var to get input to avoid having input in rcd when there's an error
    record temp {"", 0, 0};

    // Read in values
    if((is >> temp.name >> temp.id >> temp.amount))
    {
        // On success transfer them from the temporary variable
        rcd.name = temp.name;
        rcd.id = temp.id;
        rcd.amount = temp.amount;
    }else{
        // Invalid input sets failbit
        is.setstate(std::ios::failbit);
    }
    // Return input stream
    return is;
}

// Define << for record struct
std::ostream& operator<<(std::ostream& os, const record& rcd){
    // Send data to output stream
    os << rcd.name << ' ' << rcd.id << ' ' << rcd.amount;
    // Return the output stream
    return os;
}

// Function template gets a lambda for sorting comparison and outputs
template <typename Func>
void sort_and_output(std::string msg, std::vector<record> vec, Func f){
    // Message
    std::cout << "Records sorted by " << msg << ":\n";
    
    // Sort using given function
    sort(std::begin(vec), std::end(vec),
    f
    );

    // Output result to the screen
    std::copy( // Use iterators for start and end of myRecords
        std::begin(vec), std::end(vec),
        // Send myRecords content to output using ostream iterator and defined <<
        std::ostream_iterator<record>(std::cout, " ") // " " Between each record
    );

    // Output two newlines
    std::cout << "\n\n";
}

// Execution starts here
int main(){
    // Define a vector of records
    std::vector<record> myRecords;

    std::copy( // Copy using the input stream iterator and the defined >> from standard input
        std::istream_iterator<record>(std::cin), std::istream_iterator<record>(),
        // Using back_inserter iterator send read data into back of myRecords
        std::back_inserter(myRecords)
    );

    // Call sort and output three times 
    sort_and_output("name", myRecords,
    [&](const auto &a, const auto &b) -> bool
    {
        return a.name < b.name; // Sort by name
    }
    );
    sort_and_output("id", myRecords,
    [&](const auto &a, const auto &b) -> bool
    {
        return a.id < b.id; // Sort by id
    }
    );
    sort_and_output("amount", myRecords,
    [&](const auto &a, const auto &b) -> bool
    {
        return a.amount < b.amount; // Sort by amount
    }
    );
}