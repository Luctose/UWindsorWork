#ifndef comp3400_2020w_tally_hpp_
#define comp3400_2020w_tally_hpp_

//===========================================================================

#include <cstddef>   // <stddef.h> in C; for std::size_t
#include <limits>
#include <stdexcept>
#include <iostream>

//===========================================================================

class tally
{
public:
  using value_type = double;    // in C: typedef double value_type;
  using size_type = std::size_t;

private:
  size_type count_;
  value_type min_, max_, sum_, mean_, stddev_;

public:
  tally() :
    count_{},
    min_{ std::numeric_limits< value_type >::infinity() },
    max_{ -std::numeric_limits< value_type >::infinity() },
    sum_{}, 
    mean_{}, 
    stddev_{}
  {
  }

  tally(tally const&) = default;
  tally(tally&&) = default;
  tally& operator=(tally const&) = default;
  tally& operator=(tally&&) = default;
  ~tally() = default;

  size_type const& count() const { return count_; }
  value_type const& sum() const { return sum_; }

  value_type min() const
  {
    if (count_ >= 1)
      return min_;
    else if (std::numeric_limits<value_type>::has_quiet_NaN)
      return std::numeric_limits<value_type>::quiet_NaN();
    else if (std::numeric_limits<value_type>::has_signaling_NaN)
      return std::numeric_limits<value_type>::signaling_NaN();
    else
      throw std::runtime_error("invalid tally::min()");
  }
  
  value_type max() const
  {
    if (count_ >= 1)
      return max_;
    else if (std::numeric_limits<value_type>::has_quiet_NaN)
      return std::numeric_limits<value_type>::quiet_NaN();
    else if (std::numeric_limits<value_type>::has_signaling_NaN)
      return std::numeric_limits<value_type>::signaling_NaN();
    else
      throw std::runtime_error("invalid tally::max()");
  }
  
  value_type mean() const
  {
    if (count_ >= 1)
      return mean_;
    else if (std::numeric_limits<value_type>::has_quiet_NaN)
      return std::numeric_limits<value_type>::quiet_NaN();
    else if (std::numeric_limits<value_type>::has_signaling_NaN)
      return std::numeric_limits<value_type>::signaling_NaN();
    else
      throw std::runtime_error("invalid tally::mean()");
  }

  value_type stddev() const
  {
    if (count_ >= 1)
      return stddev_;
    else if (std::numeric_limits<value_type>::has_quiet_NaN)
      return std::numeric_limits<value_type>::quiet_NaN();
    else if (std::numeric_limits<value_type>::has_signaling_NaN)
      return std::numeric_limits<value_type>::signaling_NaN();
    else
      throw std::runtime_error("invalid tally::mean()");
  }

  tally& operator+=(value_type const& value)
  {
    using std::min;
    using std::max;

    ++count_;

    min_ = min(min_, value);
    max_ = max(max_, value);
    sum_ += value;

    // Use Knuth's recurrence relation from The Art of Computer Programming
    // 3rd. ed., Vol. 2, Seminumerical Algorithms, Section 4.2.2. See
    // formulas (15) and (16). Exercise 19 is not implemented here.
    value_type delta = value - mean_;
    mean_ += delta / this->count_;
    stddev_ += delta * (value - mean_);

    return *this;
  }
};

inline std::ostream& operator<<(std::ostream& os, tally const& t)
{
  os 
    << "( " 
    << t.count() << ' '
    << t.min() << ' '
    << t.max() << ' '
    << t.sum() << ' '
    << t.mean() << ' '
    << t.stddev()
    << " )"
  ;
  return os;
}

//===========================================================================

#endif // #ifndef comp3400_2020w_tally_hpp_
