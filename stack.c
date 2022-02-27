/* Simple implementation of a stack data-structure. */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  size_t* values;
  size_t length;
} Stack;

Stack* stack_init() {
  Stack* s = malloc(sizeof(Stack));
  s->length = 0;
  s->values = NULL;
  return s;
}

void stack_push(Stack* s, size_t x) {
  s->length++;

  if (!s->values) {
    s->values = malloc(sizeof(size_t));
  } else {
    s->values = realloc(s->values, s->length * sizeof(size_t));
    if (!s->values) {
        fprintf(stderr, "stack_push(): Out of memory.\n");
        exit(EXIT_FAILURE);
    }
  }

  s->values[s->length - 1] = x;
}

size_t stack_pop(Stack* s) {
  if (s->length == 0) {
    fprintf(stderr, "stack_pop(): Could not pop stack with length of 0.\n");
    exit(EXIT_FAILURE);
  }

  size_t r = s->values[s->length - 1];
  s->length--;

  if (s->length == 0) {
    free(s->values);
    s->values = NULL;
  } else {
    s->values = realloc(s->values, s->length * sizeof(size_t));
    if (!s->values) {
        fprintf(stderr, "stack_pop(): Out of memory.\n");
        exit(EXIT_FAILURE);
    }
  }

  return r;
}

size_t stack_peek(Stack* s) {
  if (s->length == 0) {
    fprintf(stderr, "stack_peek(): Could not peek stack with length of 0.\n");
    exit(EXIT_FAILURE);
  }

  return s->values[s->length - 1];
}

void free_stack(Stack* s) {
  free(s->values);
  free(s);
}

int main(void){
  Stack* s = stack_init();

  for (size_t i = 1; i <= 10; i++) {
    stack_push(s, i);
    printf("Pushes value %zu on stack, length of stack is now %zu.\n", i, s->length);
  }

  size_t peek = stack_peek(s);
  printf("Peeks value: %zu.\n", peek);

  for (size_t i = 1; i <= 10; i++) {
    size_t pop = stack_pop(s);
    printf("Pops value: %zu, new length is %zu.\n", pop, s->length);
  }

  free_stack(s);

  return EXIT_SUCCESS;
}
