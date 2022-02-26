/* Example of a simple hash function */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t hash(char* string, size_t length) {
  size_t sum = 1;
  for (size_t i = 0; i < length; i++) {
    sum *= (size_t)string[i] - 64;
  }
  return sum;
}

int main(void) {
  char* string = "BAD";
  size_t length = strlen(string);
  size_t hash_value = hash(string, length);
  printf("The hash of %s is %zu\n", string, hash_value);
}
