#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node in the middle of a linked list
void insertInMiddle(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Initialize two pointers to traverse the list
    struct Node* slow_ptr = *head;
    struct Node* fast_ptr = *head;
    struct Node* prev;

    // Move the fast pointer two steps and the slow pointer one step at a time
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    // Insert the new node between prev and slow_ptr
    prev->next = newNode;
    newNode->next = slow_ptr;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the middle of the linked list
    insertInMiddle(&head, 1);
    insertInMiddle(&head, 2);
    insertInMiddle(&head, 3);
    insertInMiddle(&head, 4);

    // Display the linked list
    displayList(head);

    return 0;
}
