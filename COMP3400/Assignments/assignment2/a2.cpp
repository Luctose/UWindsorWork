/*
Assignment 2
COMP-3400
University of Windsor
January 28 2022
By: Lucas Sarweh
ID: 110042658
*/

// Get iostream interface
#include <iostream>

// Basis class given in assignment instructions
class basis
{
    public:
        virtual ~basis(){}
        virtual std::istream& load(std::istream& is) = 0;
        virtual std::ostream& save(std::ostream& os) const = 0;
};

// Input stream operator given in assignment instructions
inline std::istream& operator>>(std::istream& is, basis& b)
{  
  return b.load(is);
}

// Output stream operator given in assignment instructions
inline std::ostream& operator<<(std::ostream& os, basis const& b)
{  
  return b.save(os);
}

// This class stores an x, y, and z for a 3D vector
class vector3d : public basis
{
    private:
        double x;
        double y;
        double z;

    public:
        // Default constructor initializes to 0
        vector3d() : x(0), y(0), z(0) {};
        // Constructor initializes based on parameters
        vector3d(double x, double y, double z) : x(x), y(y), z(z) {};

        // Loads contents from an input stream into a vector3d
        std::istream& load(std::istream& is) override{
            // Char's to take in non data characters
            char lthan, gthan, comma1, comma2;
            // Temporary vector3d so vec is not modified until the end
            // incase of a failure
            vector3d temp;

            // Get input stream that should be in the format <x,y,z> (whitespace ignored)
            if((is >> lthan >> temp.x >> comma1 >> temp.y >> comma2 >> temp.z >> gthan) &&
            lthan == '<' && comma1 == ',' && comma2 == ',' && gthan == '>'){
                // Set the vectors to temp after we have succeeded
                x = temp.x;
                y = temp.y;
                z = temp.z;
            }else{
                // Set the state of the stream to failure
                is.setstate(std::ios::failbit);
            }
            // Return input stream
            return is;
        }

        // Saves contents of a vector3d into an output stream
        std::ostream& save(std::ostream& os) const override{
            // Send data to output stream
            os << '<' << x << ',' << y << ',' << z << '>';
            // Return output stream
            return os;
        }

        // friend prototype of adding vector3d's together
        friend vector3d operator+(vector3d const& a, vector3d const& b);
};

// Add the contents of vector3d together and return result
// Friend function allows private members to be accessed
vector3d operator+(vector3d const& a, vector3d const& b){
    // Temporary vector3d to return
    vector3d temp{0, 0, 0};
    // Add x, y, z of a and b together
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    temp.z = a.z + b.z;
    // Return result
    return temp;
}

// Program starts here
int main(){
  unsigned count = 0;
  vector3d sum;
  for (vector3d v; std::cin >> v; ++count){
    sum = sum + v;
  }

  basis& bsum = sum;  // bsum uses sum polymorphically
  std::cout
    << "count: " << count << '\n'
    << "sum: " << bsum << '\n'
  ;
}