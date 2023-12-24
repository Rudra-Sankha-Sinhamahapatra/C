#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to detect a loop in a linked list using Floyd's cycle-finding algorithm
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected
            return 1;
        }
    }

    // No loop found
    return 0;
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Main function to test the loop detection
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Creating a loop for testing
    head->next->next->next->next->next = head->next->next;

    if (detectLoop(head))
        printf("Loop detected in the linked list.\n");
    else
        printf("No loop detected in the linked list.\n");

    return 0;
}