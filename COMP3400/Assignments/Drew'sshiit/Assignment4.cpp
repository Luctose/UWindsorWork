/*
Drew St. Amour
Assignment 1
January 30, 2022
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

//Defines our vectorPoints class which extends from the basis class
struct Record
{
    std::string name;
    int id;
    double amount;

};

//Defines what the << operator does for the vectorPoints data structure. Formats the output
std::ostream& operator<<(std::ostream& os, Record const& p)
{
    os << p.name << ' ' << p.id << ' ' << p.amount;
    return os;
}

//Defines what the >> operator does for the vectorPoints data structure. 
//Reads the input and sets the vector points, raises failbit error if the data given doesn't meet requirements 
std::istream& operator>>(std::istream& is, Record& p)
{

    //Creates a temperary vecortPoints to check if it fits the requirements before editing and using the original
    Record tmp;

    //Makes sure the vectorPoints is in the right format and defines our characters from earlier
    if (is >> tmp.name >> tmp.id >> tmp.amount)
    {
        //sets vectorPoints p to our temperary tmp if the format was correct
        p = tmp;
    }

    //Returns a pointer to our vectorPoints
    return is;
}

template <typename T>
void sort_and_output (string const& message, vector<Record>& vec, T test)
{
    
    cout << message << '\n';
    sort(begin(vec), end(vec), test);
    
    copy(begin(vec), end(vec), std::ostream_iterator<Record>(std::cout, "    "));
    cout << '\n' << '\n';
}

int main()
{
    vector<Record> vec;
    
    copy(
        istream_iterator<Record>(cin), istream_iterator<Record>(), 
        back_inserter(vec)
    );

    sort_and_output("Sorted by name: ", vec, [](Record i, Record j){return i.name < j.name;});
    sort_and_output("Sorted by ID: ", vec, [](Record i, Record j){return i.id < j.id;});
    sort_and_output("Sorted by amount: ", vec, [](Record i, Record j){return i.amount < j.amount;});
}
