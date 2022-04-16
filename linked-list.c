#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  size_t value;
  struct Node* next;
} Node;

Node* create_node(size_t value) {
  Node* node = malloc(sizeof(Node));
  node->value = value;
  return node;
}

Node* add_node(size_t value, Node* head) {
  Node* node = create_node(value);
  node->next = head;
  return node;
}

void print_nodes(Node* head) {
  while (head) {
    printf("Node has value: %zu\n", head->value);
    head = head->next;
  }
}

void free_nodes(Node* head) {
  while (head) {
    Node* tmp = head->next;
    free(head);
    head = tmp;
  }
}

int main(void) {
  Node* head = create_node(0);
  for (size_t i = 1; i < 10; i++) {
    head = add_node(i, head);
  }

  print_nodes(head);
  free_nodes(head);

  return EXIT_SUCCESS;
}
