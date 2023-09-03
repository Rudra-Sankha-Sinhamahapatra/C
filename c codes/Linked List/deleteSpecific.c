#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node at a specific position in the linked list
void deleteNode(struct Node** head_ref, int position) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    // If the head node needs to be deleted
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If the given position is greater than the number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    struct Node* next_node = temp->next->next;

    // Unlink the node from the linked list
    free(temp->next);

    // Link the previous node to the next node
    temp->next = next_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    struct Node* head = NULL;
    
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked List before deletion:\n");
    printList(head);

    int position = 2; // Specify the position to delete (0-based indexing)
    deleteNode(&head, position);

    printf("Linked List after deletion at position %d:\n", position);
    printList(head);

    return 0;
}