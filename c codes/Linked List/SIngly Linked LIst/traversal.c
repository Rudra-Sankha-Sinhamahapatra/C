#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next; 
};

void printLinkedList(struct Node *head){
 struct Node * current=head;
 while(current!=NULL){
    printf("%d ->",current->data);
    current=current->next;
 }
 printf("NULL\n");
}
int main() {
 struct Node * head;
 struct Node * second;
 struct Node * third;

 //Allocating memory in heap
head=(struct Node *) malloc(sizeof(struct Node));
second=(struct Node *) malloc(sizeof(struct Node));
third=(struct Node *) malloc(sizeof(struct Node));

//storing data on first node
head->data=7;
head->next=second;

//storing data on second node
second->data=11;
second->next=third;

//storing data on third node
third->data=31;
third->next=NULL;

printf("Linked List: ");
printLinkedList(head);

free(head);
free(second);
free(third);

return 0;
}