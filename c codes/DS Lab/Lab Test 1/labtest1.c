#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
int findNthFromEnd(struct Node* head, int n) {
    struct Node* first = head;
    struct Node* second = head;
    for (int i = 0; i < n; i++) {
        if (first == NULL) {
            printf("The list has fewer than %d nodes.\n", n);
            exit(1);
        }
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second->data;
}
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int n, value;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 25);
    printf("Linked List: ");
    printLinkedList(head);
    printf("Enter the value of N: ");
    scanf("%d", &n);
    value = findNthFromEnd(head, n-1);
    printf("The value at the (N-1)th node from the end is: %d\n", value);
    return 0;
}