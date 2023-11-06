// 7.3 Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue,
// Traverse, IsEmpty, IsFull using array.
// Sample Input/Output:
// Enter Queue size: 3
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. IsEmpty
// 4. IsFull
// 5. Traverse
// 6. Exit
// Enter option: 1
// Enter element: 25
// Enter option: 1
// Enter element: 36
// Enter option: 1
// Enter element: 42
// Enter option: 5
// CQueue: 25 36 42
// Enter option: 2
// Element deleted
// Enter option: 5
// CQueue: 36 42
// Enter option: 2
// Element deleted
// Enter option: 5
// CQueue: 42
// Enter option: 3
// Queue Empty: False

#include <stdio.h>

int MAX_SIZE;

int front = -1;
int rear = -1;
int cQueue[100];

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Circular Queue is Full. Cannot enqueue.\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        cQueue[rear] = data;
        printf("Element enqueued: %d\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is Empty. Cannot dequeue.\n");
    } else {
        int data = cQueue[front];
        if (front == rear) {
            front = rear = -1; // Reset the queue when the last element is dequeued
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Element dequeued: %d\n", data);
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Circular Queue is Empty.\n");
    } else {
        printf("CQueue: ");
        int i = front;
        while (1) {
            printf("%d ", cQueue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    printf("Enter Queue size: ");
    scanf("%d", &MAX_SIZE);

    do {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Circular Queue is Full. Cannot enqueue.\n");
                } else {
                    printf("Enter element: ");
                    scanf("%d", &data);
                    enqueue(data);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue Empty: True\n");
                } else {
                    printf("Queue Empty: False\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue Full: True\n");
                } else {
                    printf("Queue Full: False\n");
                }
                break;
            case 5:
                traverse();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
