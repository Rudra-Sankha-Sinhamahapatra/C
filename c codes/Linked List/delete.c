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

struct Node *deleteFromBeginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    printf("Linked List after deleting the first node: ");
    return head;
};

struct Node * deleteFromIndex(struct Node *head,int position){
    struct Node *ptr=head;
    struct Node *p = NULL;
    int i=0;
    if(position==1){
        head=deleteFromBeginning(head);
    }
    while(i<position-1 && ptr!=NULL){
        p=ptr;
        ptr=ptr->next;
        i++;
    }
    p->next=ptr->next;
    free(ptr);
    printf("Linked List after deleting from %d position: ",position);
    return head;
};

struct Node * deleteFromEnd(struct Node * head){
struct  Node *ptr=head;
struct Node *p=NULL;
while(ptr->next!=NULL){
    p=ptr;
ptr=ptr->next;
}
p->next=ptr->next;
free(ptr);
printf("Linked List After Deleting the last node: ");
return head;
};

struct Node * deleteAfteraNode(struct Node * head,struct Node * choice)
{
    struct Node *ptr=head;
    struct Node *p=NULL;
    while(ptr->next!=choice){
        p=ptr;
    ptr=ptr->next;
    }
    ptr=ptr->next;
    p=ptr;
    ptr=ptr->next;
    p->next=ptr->next;
    free(ptr);
    printf("Linked List After Deleting the Node After the selected Node is: ");
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

    // head = deleteFromBeginning(head);
    // head=deleteFromIndex(head,4);
    // head=deleteFromEnd(head);
    head=deleteAfteraNode(head,second);
    printLinkedList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}