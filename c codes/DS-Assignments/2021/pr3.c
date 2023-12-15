// i) Write the algorithm / function 
// to find the sum of alternate node’s 
// values starting from any user 
// defined position till the last in a 
// single linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

int sum_alternate_nodes(Node *head, int pos) {
  int sum = 0;
  int count = 1;
  Node *current = head;
  while (current) {
    if (count >= pos && count % 2 != 0) {
      sum += current->data;
    }
    count++;
    current = current->next;
  }
  return sum;
}

void print_list(Node *head) {
  Node *current = head;
  printf("Linked list: ");
  while (current) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  // Create the linked list
  Node *head = create_node(1);
  head->next = create_node(2);
  head->next->next = create_node(3);
  head->next->next->next = create_node(4);
  head->next->next->next->next = create_node(5);

  // Print the list
  print_list(head);

  // User-defined position
  int pos = 2;

  // Find and print the sum of alternate nodes
  int alternate_sum = sum_alternate_nodes(head, pos);
  printf("Sum of alternate nodes starting from position %d: %d\n", pos, alternate_sum);

  return 0;
}
