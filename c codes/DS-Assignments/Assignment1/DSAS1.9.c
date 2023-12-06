#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node* arb;
 struct node* next;
}; 
void point(struct node* ptr);
void traverse(struct node* ptr);
int main()
{
 int data,n,i;
 struct node* head=(struct node*)malloc(sizeof(struct node));
 struct node* temp;
 printf("Enter the number of nodes you want to create:");
 scanf("%d",&n);
 printf("\nEnter the data of node 1:");
 scanf("%d",&data);
 head->data=data;
 head->arb=NULL;
 head->next=NULL;
 temp=head;
 for(i=2;i<=n;i++)
 {
  struct node* fnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data of node %d:",i);
  scanf("%d",&data);
  fnode->data=data;
  fnode->arb=NULL;
  fnode->next=NULL;
  temp->next=fnode;
  temp=fnode;
 }
 point(head);
 traverse(head);
 return 0;
 }
 void traverse(struct node* ptr)
 {
  while(ptr!=NULL)
  {
   if(ptr->next!=NULL)
   printf("%d->",ptr->data);
   else
   printf("%d",ptr->data);
   ptr=ptr->next;
  }
 }  
  void point(struct node *ptr)
  {
   struct node *slow=ptr;
   struct node *fast=ptr->next;
   while(slow->next!=NULL)
   {
   if(slow->data < fast->data)
   {
     slow->arb=fast;
    }
   if(fast->next==NULL)
   {
    if(fast->data < ptr->data)
    fast->arb=ptr;
   }
   slow=slow->next;
   fast=fast->next;
  }
 }  
   
      
  
  
  
   
  
  
  
  
  
