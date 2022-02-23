#include <stdlib.h>
#include <stdio.h>

void selection_sort(size_t numbers[], size_t length) {
  for (size_t i = 0; i < length; i++) {
    size_t lowest_number_index = i;
    for (size_t j = i + 1; j < length; j++) {
      if (numbers[lowest_number_index] > numbers[j]) {
        lowest_number_index = j;
      }
    }
    if (lowest_number_index != i) {
      size_t tmp = numbers[i];
      numbers[i] = numbers[lowest_number_index];
      numbers[lowest_number_index] = tmp;
    }
  }
}

int main(void) {
  size_t numbers[] = { 10, 5, 2, 3, 50, 100, 1000, 17, 13, 25 };
  size_t length = sizeof(numbers) / sizeof(*numbers);

  selection_sort(numbers, length);

  for (size_t i = 0; i < length; i++) {
    printf("%zu\n", numbers[i]);
  }

  return EXIT_SUCCESS;
}
