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

void repair_isbn(unsigned char* input_code) {

  if (check_isbn(input_code)) {
    printf("Code is already correct\n");
    return;
  }

  for (int fault_position = 0; fault_position < ISBN_LENGTH - 1; fault_position++) {
    unsigned char save = input_code[fault_position];
    for (unsigned char digit = 0; digit < 10; digit++) {
      input_code[fault_position] = digit;
      if (check_isbn(input_code)) {
        printf("Fault position %d -> Corrected code: %d%d%d%d%d%d%d%d%d%d\n",
               fault_position,
               int(input_code[0]), int(input_code[1]), int(input_code[2]),
               int(input_code[3]), int(input_code[4]), int(input_code[5]),
               int(input_code[6]), int(input_code[7]), int(input_code[8]),
               int(input_code[9]));
      }
    }
    input_code[fault_position] = save;
  }
}

int main(int argc, char* argv[]) {
  unsigned char isbn_code[ISBN_LENGTH] = {0, 1, 4, 0, 3, 1, 8, 5, 9, 4};
  // printf("Is the ISBN correct? %s\n", check_isbn(isbn_code) ? "Yes" : "No");
  repair_isbn(isbn_code);
  return 0;
}
