#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  size_t length;
  size_t* values;
} Array;

Array* filter(bool (*func) (size_t), Array* array)
{
  Array* result = malloc(sizeof(Array));
  result->values = malloc(array->length * sizeof(size_t));
  result->length = array->length;

  size_t ctr = 0;
  for (size_t i = 0; i < array->length; i++)
  {
    if (func(array->values[i]))
      {
        result->values[ctr] = array->values[i];
        ctr += 1;
      }
  }
  if (ctr < array->length) {
    size_t r = realloc(result->values, ctr * sizeof(size_t));
    result->length = ctr;
  }

  return result;
}

bool isGreaterThanTen(size_t val) {
  return val > 10;
}

bool isGreaterLessTen(size_t val) {
  return val < 10;
}

bool isOddNumber(size_t val) {
  return val % 2 > 0;
}

bool isEvenNumber(size_t val) {
  return val % 2 == 0;
}

int main(void) {
  Array* numbers = malloc(sizeof(Array));
  numbers->values = (size_t[7]){ 20, 10, 1, 2, 15, 50, 100 };
  numbers->length = 7;

  Array* filtered = filter(isGreaterThanTen, numbers);

  for (size_t i = 0; i < filtered->length; i++) {
    printf("%zu\n", filtered->values[i]);
  }

  free(numbers);
  free(filtered->values);
  free(filtered);

  return EXIT_SUCCESS;
}
