// Accoring to video x^y = y^x has only one solution x = 4, y = 2 (or swapped)
// We can verify this for all (x, y) pairs where x, y belong to [0, 2^32-1]
// Taking log and rearranging the terms of the equality 
// y / log(y) = x / log(x)
// We go through t = 0 to 2^32 - 1 and compute t / log(t) and then sort the 
// values
#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main() {

  double last = double(4) / log(double(4));
  for (uint32_t t = 5; t < 0xFFFFFFFF; t++) {
    if (t % (1<<20) == 0){
      printf(".");
      fflush(stdout);
    } 

    double val = double(t) / log(double(t));
    if ( val <= last) {
      printf("Found a counter example here %u\n", t);
    }
    last = val;
  }
  return 0;
} 