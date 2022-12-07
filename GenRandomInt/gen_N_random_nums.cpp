#include <algorithm>
#include <iostream>
#include <functional>
#include <random>
#include <vector>

std::ostream& operator<< (std::ostream& out, std::vector<uint64_t> const& v)
{
    for (auto x : v) { out << x << " "; } 
    out << "\n";   
    return out;
}

void GenerateNRandomIntegers (std::vector<uint64_t>& sequence, uint64_t size, uint64_t min, uint64_t max)
{
  // std::cout << std::random_device().entropy() << "\n"; // 0 means no randomness
  std::mt19937_64 engine {std::random_device{}()};
  std::uniform_int_distribution<uint64_t> dist_min_max {min, max}; // distrubute nums ranging from min to max with equal probability
  sequence.resize(size);
  auto roll_the_die {std::bind(dist_min_max, engine)}; // randomness comes from engine
  std::generate(sequence.begin(), sequence.end(), roll_the_die);
  return;
}

int main ()
{
    std::vector<uint64_t> sequence;
    uint64_t size, min, max;
    std::cin >> size >> min >> max;
    GenerateNRandomIntegers(sequence, size, min, max);
    std::cout << sequence;
    return 0;
}