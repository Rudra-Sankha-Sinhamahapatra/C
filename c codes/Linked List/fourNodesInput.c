#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create four nodes
    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 0; i < 4; i++) {
        // Allocate memory for a new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        // Prompt user for data input
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            // If it's the first node, set it as the head
            head = newNode;
            current = newNode;
        } else {
            // Otherwise, add the new node to the end of the list
            current->next = newNode;
            current = newNode;
        }
    }

    // Print the linked list
    current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Free allocated memory
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
