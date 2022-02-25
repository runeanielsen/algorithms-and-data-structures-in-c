#include <stdlib.h>
#include <stdio.h>

void print_array(int n[], int l) {
  for (int i = 0; i < l; i++) {
    printf("%d\n", n[i]);
  }
}

void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++)
  {
    int tmp = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > tmp)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = tmp;
  }
}

int main(void) {
  int n[] = { 4, 2, 7, 1, 3 };
  int l = sizeof(n) / sizeof(*n);

  insertion_sort(n, l);
  print_array(n, l);

  return EXIT_SUCCESS;
}
