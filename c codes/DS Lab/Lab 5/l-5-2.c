// 5.2 Write a program to create a circular linked list and display the elements of the list.
// Sample Input:
// Enter no.of nodes: 5
// Enter info of node1: 30
// Enter info of node1: 50
// Enter info of node1: 40
// Enter info of node1: 20
// Enter info of node1: 70
// Sample Output:
// Clinkedlist: 30 50 40 20 70

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int numNodes, info;

    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter info of node%d: ", i + 1);
        scanf("%d", &info);
        insertNode(&head, info);
    }

    printf("Clinkedlist: ");
    displayList(head);

    return 0;
}
