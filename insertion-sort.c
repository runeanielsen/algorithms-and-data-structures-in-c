#include <stdio.h>
#include <stdlib.h>

static void print_array(size_t arr[], size_t l) {
  for (size_t i = 0; i < l; i++) {
    printf("%zu\n", arr[i]);
  }
}

static void insertion_sort(size_t arr[], size_t l) {
  for (size_t i = 1; i < l; i++) {
    size_t tmp = arr[i];
    size_t j = i;
    while (j > 0 && arr[j - 1] > tmp) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

int main(void) {
  size_t n[] = {4, 2, 7, 1, 3};
  size_t l = sizeof(n) / sizeof(*n);

  insertion_sort(n, l);
  print_array(n, l);

  return EXIT_SUCCESS;
}
