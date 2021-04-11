#include <stdio.h>

// Based on Numberphile video https://www.youtube.com/watch?v=sPFWfAxIiwg

// Input: Incorrect ISBN code
// Output: Corrected ISBN code
// Key assumptions would be regarding how many digits of error we assume. If the
// error is restricted to any one digit, then it could be corrected uniquely.
// For 2 or more incorrect digits, the possible solutions would be more than one
// The program is supposed to enumerate possible solution in optimal way.

const int ISBN_LENGTH = 10;

bool check_isbn(unsigned char* code) {
  int sum = 0;
  for (int i = 0; i < ISBN_LENGTH - 1; i++) {
    sum = (sum + (code[i] * (10 - i))) % 11;
  }
  if (sum + code[ISBN_LENGTH - 1] == 0 || sum + code[ISBN_LENGTH - 1] == 11) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char* argv[]) {
  unsigned char isbn_code[ISBN_LENGTH] = {0, 1, 4, 0, 3, 1, 8, 1, 9, 4};
  printf("Is the ISBN correct? %s\n", check_isbn(isbn_code) ? "Yes" : "No");
  return 0;
}
