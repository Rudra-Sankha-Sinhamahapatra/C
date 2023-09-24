#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to input data for the doubly linked list
struct Node* inputDoublyLinkedList(int numNodes) {
    int data;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

// Function to traverse and print the doubly linked list forward
void printDoublyLinkedListForward(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to traverse and print the doubly linked list backward
void printDoublyLinkedListBackward(struct Node* tail) {
    struct Node* current = tail;
    printf("Doubly Linked List (Backward): NULL ");
    while (current != NULL) {
        printf("<-> %d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeDoublyLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int numNodes;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    struct Node* head = inputDoublyLinkedList(numNodes);

    printDoublyLinkedListForward(head);
    printDoublyLinkedListBackward(head); // Note that you can pass the tail if you have it.

    freeDoublyLinkedList(head); // Free the memory to prevent memory leaks

    return 0;
}
