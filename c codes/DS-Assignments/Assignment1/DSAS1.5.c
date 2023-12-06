#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void traverse(struct node *ptr);
bool detectAndRemoveLoop(struct node *head);
int main() {
    int data, i, res;
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the data of the 1st node:\n");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= 5; i++) {
        printf("Enter the data of the %d node:\n", i);
        scanf("%d", &data);
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    head->next->next->next->next->next = head;
    res = detectAndRemoveLoop(head);
    
    if (res == 1)
        printf("\nTrue");
    else
        printf("\nFalse");

    traverse(head);
}

void traverse(struct node *ptr) {
    printf("\n");
    while (ptr != NULL) {
        if (ptr->next == NULL)
            printf("%d", ptr->data);
        else
            printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

bool detectAndRemoveLoop(struct node *head) {
    int res = 0;
    struct node *slow = head;
    struct node *fast = head;
    struct node *prev = NULL; // Keep track of the previous node

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            res = 1;
            break;
        }
        prev = slow;
    }

    if (res == 1) {
        // Remove the loop
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }

    return res;
}

