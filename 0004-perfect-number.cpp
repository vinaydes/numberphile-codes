// Reference: https://www.youtube.com/watch?v=ZfKTD5lvToE 8128 and Perfect Numbers
// This code should print all the perfect numbers that are less than 2^32
// Idea is to use sieving technique for searching.
#include <array>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

constexpr size_t SIEVE_LENGTH = 65536;

template <size_t sieve_length>
void batch_sieve(std::vector<uint32_t>& perfect_numbers, uint32_t sieve_start,
                 std::array<uint32_t, sieve_length>& sieve_array) {

  uint32_t sieve_end = sieve_start + sieve_length - 1;
  uint32_t biggest_factor = sieve_end / 2;

  std::fill(sieve_array.begin(), sieve_array.end(), 0);

  uint32_t l;
  for (uint32_t f = 1; f <= biggest_factor; f++) {
    uint32_t remainder = sieve_start % f;
    l = 0;
    
    // Find the first number in the range that is divisible by f
    while (remainder != 0) {
      remainder++;
      if (remainder == f) remainder = 0;
      l++;
    }
    
    // Now find rest of the numbers that are divisible by f and update sieve_array
    for (; l < sieve_length; l += f) {
      if (sieve_start + l != f) {
        sieve_array[l] += f;
      }
      // if (sieve_start + l == 500) {
      //   std::cout << "500 is divisible by: " << f << "\n";
      // }
    }
  }
  // Look out for perfect numbers
  for (l = 0; l < sieve_length; l++) {
    if (sieve_start + l == sieve_array[l]) {
      perfect_numbers.push_back(sieve_start + l);
    }
  }
  return;
}

int main() {
  std::array<uint32_t, SIEVE_LENGTH> sieve_array = {};
  std::vector<uint32_t> perfect_numbers;

  for (size_t start = 1; start <= 0xFFFFFFFF; start += SIEVE_LENGTH) {
    batch_sieve<SIEVE_LENGTH>(perfect_numbers, start, sieve_array);
    std::cout << start << "\n";
  }
  
  for (int i = 0; i < perfect_numbers.size(); i++) {
    std::cout << perfect_numbers[i] << "\n";
  }

  return 0;
}