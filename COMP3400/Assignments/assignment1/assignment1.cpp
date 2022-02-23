/*
Assignment 1
COMP-3400
University of Windsor
January 21 2022
By: Lucas Sarweh
ID: 110042658
*/

// Get the iostream interface
#include <iostream>

// This struct stores an x, y, and z for a 3D vector
struct vector3d
{
    double x;
    double y;
    double z;
};

// Define operator << to send values of vector to output stream
std::ostream& operator<<(std::ostream& os, vector3d const& vec){
    // Send data to output stream
    os << '<' << vec.x << ',' << vec.y << ',' << vec.z << '>';
    // Return output stream
    return os;
}

// Define operator >> to send info in input stream to a vector3d
std::istream& operator>>(std::istream& is, vector3d& vec){
    // Char's to take in non data characters
    char lthan, gthan, comma1, comma2;
    // Temporary vector3d so vec is not modified until the end
    // incase of an failure
    vector3d temp;

    // Get input stream that should be in the format <x,y,z> (whitespace ignored)
    if((is >> lthan >> temp.x >> comma1 >> temp.y >> comma2 >> temp.z >> gthan) &&
    lthan == '<' && comma1 == ',' && comma2 == ',' && gthan == '>'){
        // Set vec to temp after we have succeeded
        vec = temp;
    }else{
        // Set the state of the stream to failure
        is.setstate(std::ios::failbit);
    }
    // Return input stream
    return is;
}

// Define binary operator += which increases the right side by the left
vector3d& operator+=(vector3d& left, vector3d const& right){
    // Add the right x,y,z to the left x,y,z
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    // Return the result
    return left;
}

// Execution starts here
int main(){
    // Disable C-style I/O for iostream performance
    std::ios_base::sync_with_stdio(false);
    
    // Count of vectors read
    int count = 0;
    // Define summing vector
    vector3d sum {0, 0, 0};
    // Define vector to hold inputs
    vector3d holder {0, 0, 0};

    // Read next vector
    while(std::cin >> holder){
        // Increment count
        count++;
        // Add the vector in holder to the sum
        sum += holder;
    }
    // Print the count to cout
    std::cout << "count: " << count << '\n';
    // Print the vector sum to cout
    std::cout << "sum: " << sum << '\n';
}