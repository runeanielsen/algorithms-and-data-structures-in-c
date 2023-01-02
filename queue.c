/* Implementation of a dynamic array based queue. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t capacity;
  size_t length;
  size_t *values;
} Queue;

Queue *queue_init(size_t capacity) {
  Queue *q = malloc(sizeof(Queue));
  q->capacity = capacity;
  q->length = 0;
  q->values = malloc(capacity * sizeof(size_t));
  return q;
}

void queue_enqueue(Queue *q, size_t x) {
  if (q->length == q->capacity) {
    q->capacity *= 2;
    q->values = realloc(q->values, q->capacity * sizeof(size_t));
    if (!q->values) {
      fprintf(stderr, "queue_enqueue(): Out of memory.\n");
      exit(EXIT_FAILURE);
    }
  }
  q->values[q->length] = x;
  q->length++;
}

size_t queue_dequeue(Queue *q) {
  if (!q->length) {
    fprintf(stderr, "queue_dequeue(): Could not dequeue when length is 0.\n");
    exit(EXIT_FAILURE);
  }
  size_t r = q->values[0];
  q->length--;
  for (size_t i = 0; i < q->length; i++) {
    q->values[i] = q->values[i + 1];
  }
  return r;
}

size_t queue_read(Queue *q) {
  size_t r = q->values[0];
  return r;
}

void free_queue(Queue *q) {
  free(q->values);
  free(q);
}

int main(void) {
  size_t iterations = 20;
  Queue *q = queue_init(8);

  for (size_t i = 1; i <= iterations; i++) {
    queue_enqueue(q, i);
  }

  size_t r = queue_read(q);
  printf("Reads value %zu without doing a dequeue.\n", r);

  for (size_t i = 1; i <= iterations; i++) {
    size_t d = queue_dequeue(q);
    printf("Dequeues got value %zu, and length of queue is now %zu.\n", d,
           q->length);
  }

  free_queue(q);
}
