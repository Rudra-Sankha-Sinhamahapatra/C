// 8.2 Write a menu driven program to implement priority queue operations such as Enqueue, Dequeue,
// Traverse using linked list.
// Sample Input/Output:
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter option: 1
// Enter element: 34
// Enter priority: 1
// Enter option: 1
// Enter element: 23
// Enter priority: 3
// Enter option: 1
// Enter element: 46
// Enter priority: 2
// Enter option: 3
// Priority Queue:
// Priority Item
// 1 34
// 2 46
// 3 23

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** front, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element %d with priority %d enqueued successfully.\n", data, priority);
}

void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);

    printf("Element dequeued successfully.\n");
}

void display(struct Node* front) {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    printf("Priority   Item\n");
    while (front != NULL) {
        printf("%-10d%d\n", front->priority, front->data);
        front = front->next;
    }
}

int main() {
    struct Node* front = NULL;
    int option, element, priority;

    do {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&front, element, priority);
                break;
            case 2:
                dequeue(&front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}

