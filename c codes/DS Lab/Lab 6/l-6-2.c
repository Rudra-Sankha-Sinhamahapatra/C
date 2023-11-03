// 6.2 Write a menu driven program to create a stack using linked list and perform the following operation
// using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements
// Sample Input/Output:
// Main Menu
// 1. Push
// 2. Pop
// 3. IsEmpty
// 4. Traverse
// 5. Exit
// Enter option: 1
// Enter element to be pushed into the stack: 12
// Enter option: 1
// Enter element to be pushed into the stack: 35
// Enter option: 1
// Enter element to be pushed into the stack: 24
// Enter option: 1
// Enter element to be pushed into the stack: 8
// Enter option: 1
// Enter element to be pushed into the stack: 41
// Enter option: 4
// Stack: 41 8 24 35 12
// Enter option: 2
// 41 deleted from Stack

#include <stdio.h>
#include <stdlib.h>
#define max 10

int top = -1;

struct node {
    int data;
    struct node* next;
};

struct node* push(struct node* head);
int pop(struct node** head);
int isEmpty(struct node* head);
void display(struct node* head);
struct node* reverse(struct node* head);
int main() {
    struct node* head = NULL;
    int ch, res;

    do {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.IsEmpty");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                head = push(head);
                break;
            case 2:
                res = pop(&head);
                if (res == -1)
                    printf("\nStack Underflow");
                else
                    printf("\nThe element deleted is %d", res);
                break;
            case 3:
                res = isEmpty(head);
                if (res == -1)
                    printf("\nStack is empty");
                else
                    printf("\nThe stack is not empty");
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nWrong choice entered");
                break;
        }
    } while (1);
}

struct node* push(struct node* head) {
    if (top == max - 1) {
        printf("\nStack overflow");
    } else {
        top++;
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        int element;
        printf("\nEnter the element you want to enter: ");
        scanf("%d", &element);
        newnode->data = element;
        newnode->next = head;
        head = newnode;
    }
    return head;
}

int pop(struct node** head) {
    if (top == -1 || *head == NULL) {
        return -1;
    } else {
        top--;
        struct node* ptr = *head;
        int data = ptr->data;
        *head = ptr->next;
        free(ptr);
        return data;
    }
}

int isEmpty(struct node* head) {
    if (top == -1 || head == NULL)
        return -1;
    else
        return 0;
}

void display(struct node* head) {
    if (top == -1 || head == NULL) {
        printf("\nStack is empty");
    } else {
        head=reverse(head);
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
struct node* reverse(struct node* head)
   {
    struct node* fast=NULL;
    struct node* current=head;
    struct node* slow=NULL;
    while(current!=NULL)
    {
     fast=current->next;
     current->next=slow;
     slow=current;
     current=fast;
    }
    return slow;
   }  





