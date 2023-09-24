#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
 };
void swap(struct node *ptr);
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
 printf("\nThe list you entered:");
 traverse(head);
 printf("\nThe new list after swapping pairwise:");
 swap(head);
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
 void swap(struct node *ptr)
 {
  int data;
  struct node *p=ptr->next;
  while(ptr->next!=NULL)
  {
    data=p->data;
    p->data=ptr->data;
    ptr->data=data;
    if(p->next==NULL)
    break;
    ptr=ptr->next->next;
    p=p->next->next;
  }
 }   
  
  
  
  
  
  
  
  
  
  
      
 
 
 
 
 
 
 
 
 
