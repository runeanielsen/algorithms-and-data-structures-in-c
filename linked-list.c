#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

typedef struct Node {
  size_t number;
  struct Node* next;
} Node;

void print_list(Node* n) {
  while(n) {
    printf("Number is %zu\n", n->number);
    n = n->next;
  }
}

Node* add(size_t number, Node* head) {
  Node* new_head = malloc(sizeof(Node));
  *new_head = (Node){ .number = number, .next = head };
  return new_head;
}

void free_nodes(Node* head) {
  while (head) {
    Node* tmp = head->next;
    free(head);
    head = tmp;
  }
}

int main(void) {
  size_t size = 500;
  Node* head = malloc(sizeof(Node));
  head->number = 0;

  for (size_t i = 1; i < size; i++) {
    head = add(i, head);
  }

  // To show how to free the linked-list from memory.
  free_nodes(head);

  return EXIT_SUCCESS;
}
