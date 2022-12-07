#include <algorithm>
#include <chrono>
#include <iostream>
#include <functional>
#include <numeric>
#include <random>
#include <vector>

void GenerateNRandomIntegers (std::vector<uint64_t>& sequence, uint64_t n)
{
  // std::cout << std::random_device().entropy() << "\n"; // 0 means no randomness
  // std::mt19937_64 engine {std::random_device{}()};
  std::mt19937_64 engine(std::chrono::system_clock::now().time_since_epoch().count());// obtain a time-based seed:
  // std::uniform_int_distribution<uint64_t> dist_1_n {1, n}; // a big die
  sequence.resize(n);
  // auto roll_the_die {std::bind(dist_1_n, engine)}; // randomness comes from engine
  // std::generate(sequence.begin(), sequence.end(), roll_the_die);
  std::iota(sequence.begin(), sequence.end(), 0);
  std::shuffle(sequence.begin(), sequence.end(), engine);
  return;
}

void Print (std::vector<uint64_t> const& v)
{
  for (auto const& x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return;
}

template <typename Iterator> // will be replaced with std::vector<uint64_t>::iterator
void Print (Iterator first, Iterator last)
{
  for (auto it {first}; it != last; ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  return;
}

template <typename Iterator> // will be replaced with std::vector<uint64_t>::iterator
void InsertionSort (Iterator first, Iterator last)
{
  auto it {std::next(first, 1)};
  while (it != last)
  {
    auto rit {it};
    while (rit != first && *std::prev(rit) > *rit) 
    { 
      std::swap(*std::prev(rit), *rit);
      --rit;
    }
    ++it;
  }
  return;
}

template <typename Iterator>
std::vector<uint64_t>::iterator MoveMediansToFront (Iterator begin, Iterator end)
{
  auto it_median {begin};
  auto it {std::next(begin, 2)};
  while (it < end)
  {
    std::swap(*it, *it_median);
    std::advance(it_median, 1);
    std::advance(it, 5);
  }
  return it_median;
}

template <typename Iterator>
uint64_t SelectKthSmallestElement (Iterator begin, Iterator end, uint64_t k)
{
  for (auto it {begin}; it < end; std::advance(it, 5))
  {
    InsertionSort(it, (std::next(it, 5) < end ? std::next(it, 5) : end));
  }
  if (std::distance(begin, end) <= 5) { return *std::next(begin, k); }
  // {
  //   std::cout << "insertion sort: ";
  //   Print(begin, end);
  // }
  auto last_median {MoveMediansToFront(begin, end)};
  // {
  //   std::cout << "move medians to front: ";
  //   Print(begin, end);
  // }
  auto median_of_medians {SelectKthSmallestElement(begin, last_median, (std::distance(begin, last_median) - 1) / 2)};
  // std::cout << "median of medians: " << median_of_medians << "\n";
  auto count
  {
    std::count_if // if it's kth smallest, index = k-1, so there're k-1 numbers smaller than it.
    (
      begin, 
      end,
      [median_of_medians] (auto const& element) { return (element < median_of_medians); } 
    )
  };
  // std::cout << "rank of median of median: " << count << "\n";
  if (count < k)
  {
    auto last
    {
      std::partition
      (
        begin,
        end,
        [median_of_medians] (auto const& element) { return element >= median_of_medians; }
      )
    };
    // {
    //   std::cout << "rank of median of medians < k: ";
    //   Print(begin, last);
    //   std::cout << "next k: " << (k - count) << "\n";
    // }
    return SelectKthSmallestElement(begin, last, k - count);
  }
  else if (count > k)
  {
    auto last
    {
      std::partition
      (
        begin,
        end,
        [median_of_medians] (auto const& element) { return element <= median_of_medians; }
      )
    };
    // {
    //   std::cout << "rank of median of medians > k: ";
    //   Print(begin, last);
    //   std::cout << "next k: " << k << "\n";
    // }
    return SelectKthSmallestElement(begin, last, k);
  }
  return median_of_medians;
}

int main ()
{  
  uint64_t n {};
  std::cin >> n;
  std::vector<uint64_t> v;
  GenerateNRandomIntegers(v, n);  
  //for (uint64_t k {}; k != n; ++k)
  //{
  uint64_t k {};
  std::cin >> k; // k from 0th smallest to (n-1)th smallest
  std::vector<uint64_t> buffer(v);
  // {
  //   std::cout << "origin: ";
  //   Print(buffer);
  // }
  std::cout << "select(" << n << ", " << k << "): "; 
  if (SelectKthSmallestElement(buffer.begin(), buffer.end(), k) != k)
  {
    std::cout << "no, debug it.\n";
  }
  else
  {
    std::cout << "Nice! it works.\n";
  }
  //}
  return 0;
}