// i)Assume in a school some 
// students are standing in a circular 
// way where each student is holding 
// the hands of the students standing 
// on both the sides. Write the c 
// program / algorithm to visit all 
// the students once only.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

void visit_students(Node *head) {
  Node *current = head;
  do {
    // Visit the current student
    printf("Student %d visited.\n", current->data);

    // Move to the next student
    current = current->next;
  } while (current != head);
}

int main() {
  // Create nodes for the students
  Node *student1 = create_node(1);
  Node *student2 = create_node(2);
  Node *student3 = create_node(3);
  Node *student4 = create_node(4);

  // Connect the nodes in a circle
  student1->next = student2;
  student2->next = student3;
  student3->next = student4;
  student4->next = student1;

  student1->prev = student4;
  student2->prev = student1;
  student3->prev = student2;
  student4->prev = student3;

  // Start the visit from student 1
  visit_students(student1);

  return 0;
}