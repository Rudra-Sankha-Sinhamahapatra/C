// 5. Write C function to Finding a loop in the singly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int hasLoop(struct Node* head) {
    struct Node *slow, *fast;
    slow = fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    second->next = NULL;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;
    third->next = NULL;

    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 4;
    fourth->next = NULL;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    int result = hasLoop(head);
    printf("Has Loop: %s\n", result ? "Yes" : "No");

    return 0;
}
