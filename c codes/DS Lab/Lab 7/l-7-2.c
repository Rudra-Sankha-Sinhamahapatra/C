// 7.2 Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,
// IsEmpty, Traverse using single linked list.
// Sample Input/Output:
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. IsEmpty
// 4. Traverse
// 5. Exit
// Enter option: 1
// Enter element: 55
// Enter option: 1
// Enter element: 23
// Enter option: 1
// Enter element: 46
// Enter option: 4
// Queue: 55 23 46
// Enter option: 2
// Element deleted
// Enter option: 4
// Queue: 23 46


#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue(){
    struct Node* temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
}

int isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

void traverse(){
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, x;
    do{
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");

        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the value to enqueue:\n");
                    scanf("%d", &x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: if(isEmpty())
                        printf("Queue is empty\n");
                    else
                        printf("Queue is not empty\n");
                    break;
            case 4: traverse();
                    break;
        }
    }while(choice!=5);
    return 0;
}