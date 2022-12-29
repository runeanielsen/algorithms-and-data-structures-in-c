#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  size_t value;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *start;
  Node *end;
} LinkedList;

static void init_linked_list(LinkedList *linked_list, Node *node) {
  linked_list->end = node;
  linked_list->start = node;
}

static Node *new_node(size_t value) {
  Node *n = malloc(sizeof(Node));
  n->value = value;
  n->next = NULL;
  return n;
}

static void print_nodes(const LinkedList *linked_list) {
  Node *head = linked_list->start;
  while (head) {
    printf("Node value is: %zu\n", head->value);
    head = head->next;
  }
}

static void append_node(LinkedList *linked_list, Node *next) {
  linked_list->end->next = next;
  linked_list->end = next;
}

static void free_nodes(LinkedList *linked_list) {
  Node *head = linked_list->start;
  while (head) {
    Node *tmp = head->next;
    free(head);
    head = tmp;
  }
}

int main() {
  LinkedList my_linked_list;
  init_linked_list(&my_linked_list, new_node(0));

  for (size_t i = 1; i < 100; i++) {
    append_node(&my_linked_list, new_node(i * 100));
  }

  print_nodes(&my_linked_list);

  free_nodes(&my_linked_list);

  return EXIT_SUCCESS;
}
