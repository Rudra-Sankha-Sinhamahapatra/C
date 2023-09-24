#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
}; 
void deleteatposition(struct node *ptr,int pos);
void removeDuplicates(struct node *ptr);
void traverse(struct node *ptr);
int main()
{
 int data,n,i;
 struct node *head=(struct node*)malloc(sizeof(struct node));
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter the no. of nodes you want to create:\n");
 scanf("%d",&n);
 printf("Enter the data of the 1st node:\n");
 scanf("%d",&data);
 head->data=data;
 head->next=NULL;
 temp=head;
 for(i=2;i<=n;i++)
 {
  printf("Enter the data of the %d node:\n",i);
  scanf("%d",&data);
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
  temp->next=newnode;  
  temp=newnode;
 }
 printf("\nThe list you entered is: ");
 traverse(head);
 removeDuplicates(head);
 printf("\nThe list after removing all the duplicates is:");
 traverse(head);
 }
 void traverse(struct node *ptr)
 {
  
  while(ptr!=NULL)
  {
   if(ptr->next==NULL)
   printf("%d",ptr->data);
   else
   printf("%d->",ptr->data);
   ptr=ptr->next;
  }
 }  
 void removeDuplicates(struct node* ptr)
{
   struct node *ptr1, *ptr2, *dup;
    ptr1 = ptr;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else 
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
     
 
  
     
     
     
     
     
     
     
     
     
      
 
 
 
 
 
 
 
 
 
 
 
 
 
 
