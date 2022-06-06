//
// See Chapter 14 in The C++ Standard Library: A Tutorial and Reference for
// more details on regular expressions. :-)
//
// Raw string literals were used below as R"delim( to )delim". Know that
// "delim" can be omitted or some other name that is not part of the
// raw string. Typically, one usually sees R"( and )" to define a raw
// string --but then )" cannot appear within the raw string (this is
// why the delim text is permitted).
//
// When compiled and run this program will output:
//   RESULT:    input:
//   RESULT: (8   input: 8
//   RESULT: (80   input: 80
//   RESULT: (800)    input: 800
//   RESULT: (800) 1   input: 8001
//   RESULT: (800) 12   input: 80012
//   RESULT: (800) 123-   input: 800123
//   RESULT: (800) 123-4   input: 8001234
//   RESULT: (800) 123-45   input: 80012345
//   RESULT: (800) 123-456   input: 800123456
//   RESULT: (800) 123-4567   input: 8001234567
//
#include <string>
#include <regex>
#include <iostream>

using namespace std;

//
// regex_demo(input)
// function
//
// The regex_demo() function accepts a string as input which is made up of
// only digit characters (up to 10). (The input is to be the 10 digits of a
// North American phone number w/country code 1 being implicit.)
//
// The regex_demo() function will extract the digits from the input in to
// three groups in order to format it in this form (111) 222-3333 where
// 1, 2, and 3 represents single digits in groups 1, 2, and 3.
//
void regex_demo(std::string const& input)
{
  using namespace std::literals;

  //
  // The regex is static to only compile this regex once --not
  // each time this function is called...
  //
  // \d{0,3} and \d{0,4} are used to do partial matches of digits,
  // 0 to 3 and 0 to 4 respectively. This is to allow partial matches
  // when there is insufficient input for a full match. Why do this?
  // If one had only supplied two digits, then one would want to see
  // (##, i.e., the beginning of the first ( and not the closing ), etc.
  //
  // ASIDE: Normally one might write (\d{3})(\d{3})(\d{4}) except here
  //        the aim is to interactively show partial matches with 
  //        replacements involving added text, e.g., suppose this was
  //        used with an input routine with real-time feedback 
  //        of a user entering in a phone number.
  //
  static regex const incremental_phone_num_regex( 
    R"delim((\d{0,3})(\d{0,3})(\d{0,4}))delim" );

  //
  // Four regex_replacement strings are used:
  //   [0] is used for an empty string,
  //   [1] is used for input that can only partially fill in group 1
  //   [2] is used for input that can only partially fill in group 2
  //   [3] is used for input that can fill in group 3
  // Effectively, this can be used in an interactive program to create a
  // formatted phone number string from user input.
  //
  string const na_phone_num[] { 
    { R"delim()delim"s },             // output nothing
    { R"delim(($1)delim"s },          // output ( then digits
    { R"delim(($1) $2)delim"s },      // output (111) then digits
    { R"delim(($1) $2-$3)delim"s }    // output (111) 222- then digits
  };

  //
  // Use regex_search() to determine the length of each matched group/
  // subexpression.
  //
  smatch m; // variable to hold results of regex_search
  regex_search(
    input, m, incremental_phone_num_regex, 
    regex_constants::match_not_null // an empty sequence shall not match
    | regex_constants::format_no_copy // don't copy characters that don't match
  );

  // Compute the total length of all matched groups...
  int total_length = 0;
  for (int i=1; i < m.size(); ++i)
    total_length += m[i].length();

  // Determine the na_phone_num index to use based on total_length...
  int na_phone_num_index = 0;
  if (total_length >= 6)
    na_phone_num_index = 3;
  else if (total_length >= 3)
    na_phone_num_index = 2;
  else if (total_length > 0)
    na_phone_num_index = 1;

  // Transform input in to (111) 222-3333 only showing appropriate 
  // "() -" characters when sufficient numbers of digits 
  // have been provided...
  cout 
    << "  RESULT: " 
    << regex_replace(
         input, 
         incremental_phone_num_regex,
         na_phone_num[na_phone_num_index],
         regex_constants::match_not_null // an empty sequence shall not match
         | regex_constants::format_no_copy // don't copy characters that don't match
       ) 
    << "   input: " << input
    << '\n'
  ;
}

int main()
{
  // NOTE: input needs to be a string of digits. If this was coming from 
  //       user input, one would sanitize the input first (e.g., only
  //       allowing isdigit() characters to be accepted as input placed
  //       in to the string).
  std::string input = "8001234567";
 
  // call regex_demo with strings of zero size to size()-1...
  for (auto last = begin(input); last != end(input); ++last)
    regex_demo(string(begin(input), last));

  // call regex_demo a last time with entire string...
  regex_demo(input);
}

