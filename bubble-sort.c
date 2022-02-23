#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void print_array(size_t x[], size_t length) {
  for (size_t i = 0; i < length; i++) {
    printf("%zu\n", x[i]);
  }
}

void bubble_sort(size_t x[], size_t length) {
  bool sorted = false;
  size_t unsorted_until_index = length - 1;
  while (!sorted) {
    sorted = true;
    for (size_t i = 0; i < unsorted_until_index; i++) {
      if (x[i] > x[i + 1]) {
        size_t tmp = x[i];
        x[i] = x[i + 1];
        x[i + 1] = tmp;
        sorted = false;
      }
    }
    unsorted_until_index -= 1;
  }
}

int main() {
  size_t x[] = { 2, 1, 15, 20, 60, 11, 16, 5, 22, 50, 100, 23};
  size_t l = sizeof(x) / sizeof(*x);

  bubble_sort(x, l);
  print_array(x, l);

  return EXIT_SUCCESS;
}
