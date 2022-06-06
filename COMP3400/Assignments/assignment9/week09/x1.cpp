#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

class mystr
{
private:
  size_t sz_;
  char *buf_;

public:
  mystr() :
    buf_{ new char[1] },
    sz_{0}
  {
    *buf_ = '\0';
  }

  ~mystr()
  {
    delete[] buf_;
  }
};

class mystr2
{
private:
  struct rep
  {
    size_t sz_;
    char buf_[1];
  };

  alignas(rep) char* repbuf_;
  rep* rep_;

public:
  mystr2() :
    mystr2(0)
  {
  }

  mystr2(size_t max_num_of_chars_in_str) :
    repbuf_{nullptr}
  {
    size_t adjusted_rep_memory_size = max_num_of_chars_in_str+1 + sizeof(rep)-1;

    // first, allocate the memory needed to hold max_num_of_chars_in_str + size_t in rep :-)
    repbuf_ = new char[adjusted_rep_memory_size];

    // second, placement new "allocate" at repbuf_ location 
    rep_ = new(repbuf_) rep;

    rep_->sz_ = max_num_of_chars_in_str;
    rep_->buf_[0] = '\0';
  }

  ~mystr2()
  {
    // placement new "allocated" objects must be manually destroyed...
    rep_->~rep();

    // free the RAM...
    delete[] repbuf_;
  }
};

int main()
{
  cout << sizeof(mystr) << ' ' << alignof(mystr) << '\n';
  cout << sizeof(std::string) << ' ' << alignof(std::string) << '\n';
  cout << sizeof(mystr2) << ' ' << alignof(mystr2) << '\n';

  // ... SSO (short string optimization) ...
}

