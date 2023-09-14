#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node * insertAtBeginning(struct Node * head,int data){
  struct Node * ptr=(struct Node *) malloc( sizeof(struct Node));
  ptr->next=head;
  ptr->data=data;
  printf("Linked list after inserting %d at beginning: ",data);
  return ptr;
};

struct Node * insertAtIndex(struct Node * head,int data,int middle){
struct Node * ptr=(struct Node *) malloc( sizeof(struct Node));
struct Node * p= head;
int i=0;
while (i!=middle-1)
{
    p=p->next;
    i++;
}
ptr->data=data;
ptr->next= p->next;
p->next=ptr;
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

    // storing data on first node
    head->data = 7;
    head->next = second;

    // storing data on second node
    second->data = 11;
    second->next = third;

    // storing data on third node
    third->data = 31;
    third->next = fourth;

    // storing data on fourth node
    fourth->data = 56;
    fourth->next = NULL;

    printf("Linked List: ");
    printLinkedList(head);
    // head=insertAtBeginning(head,24);
    head=insertAtIndex(head,24,2);
       printLinkedList(head);
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}