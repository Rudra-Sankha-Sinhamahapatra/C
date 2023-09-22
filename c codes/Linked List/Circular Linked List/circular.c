#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("%d->", p->data);
        p = p->next;

    } while (p != head);
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }
    // at this time p points to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head=ptr;
    printf("\nCircular Linked List After Inserting Element at the beginning: ");
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Allocating memory in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // connecting head and second node
    head->data = 4;
    head->next = second;

    // connecting  second and third node
    second->data = 3;
    second->next = third;

    // connecting third and fourth node
    third->data = 6;
    third->next = fourth;

    // connectimg fourth and head node
    fourth->data = 1;
    fourth->next = head;

    printf("Circular Linked List: ");
    linkedListTraversal(head);
    head = insertAtBeginning(head, 24);
    linkedListTraversal(head);

    return 0;
}