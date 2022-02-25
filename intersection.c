#include <stdlib.h>
#include <stdio.h>

typedef struct  {
  size_t length;
  size_t* values;
} Array;

void print_array(Array* a) {
  for (size_t i = 0; i < a->length; i++) {
    printf("%zu\n", a->values[i]);
  }
}

Array* intersection(Array* a1, Array* a2) {
  Array* result = malloc(sizeof(Array));
  result->values = malloc(0);
  result->length = 0;

  for (size_t i = 0; i < a1->length; i++) {
    for (size_t j = 0; j < a2->length; j++) {
      if (a1->values[i] == a2->values[j]) {
        result->length++;
        size_t* tmp = realloc(result->values, result->length * sizeof(size_t));
        if (tmp) {
          result->values[result->length - 1] = a1->values[i];
          break;
        } else {
          fprintf(stderr, "Could not realloc result.");
          exit(EXIT_FAILURE);
        }
      }
    }
  }

  return result;
}

int main(void) {
  Array* a1 = malloc(sizeof(Array));
  a1->values = malloc(4 * sizeof(size_t));
  a1->length = 4;
  a1->values[0] = 10;
  a1->values[1] = 5;
  a1->values[2] = 2;
  a1->values[3] = 25;

  Array* a2 = malloc(sizeof(Array));
  a2->values = malloc(4 * sizeof(size_t));
  a2->length = 4;
  a2->values[0] = 3;
  a2->values[1] = 23;
  a2->values[2] = 10;
  a2->values[3] = 5;

  Array* intersections = intersection(a1, a2);
  print_array(intersections);

  free(intersections->values);
  free(intersections);
  free(a1->values);
  free(a2->values);
  free(a1);
  free(a2);

  return EXIT_SUCCESS;
}
