#include <stdio.h>
#include <stdint.h>

// Based on Numberphile video https://www.youtube.com/watch?v=umYvFdU54Po
// In this program we detect overflow in addition

uint32_t add_with_overflow(uint32_t& sum, uint32_t a, uint32_t b) {
  sum = a + b;
  if (sum < a)
    return 1;
  else
    return 0;
}

int main() {
  uint32_t carry, sum;
  carry = add_with_overflow(sum, uint32_t(3641687558), uint32_t(3284498138));
  printf("%u, %u\n", carry, sum);

  return 0;
}