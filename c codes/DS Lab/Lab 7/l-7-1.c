// 7.1 Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue,
// Traverse, IsEmpty, IsFull operations.
// Sample Input/Output:
// Enter the size of Queue: 5
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. IsEmpty
// 4. IsFull
// 5. Traverse
// 6. Exit
// Enter option: 1
// Enter element: 15
// Enter option: 1
// Enter element: 23
// Enter option: 1
// Enter element: 40
// Enter option: 5
// Queue: 15 23 40
// Enter option: 2
// Element deleted
// Enter option: 5
// Queue: 23 40

#include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max];
int rear=-1,front=-1;
void enqueue(int x);
int dequeue();
int IsEmpty();
int IsFull();
void display();
int main()
{
 int res,ch,x;
 do
 {
  printf("\n1.Enqueue");
  printf("\n2.Dequeue");
  printf("\n3.IsEmpty");
  printf("\n4.IsFull");
  printf("\n5.Traverse");
  printf("\n6.Exit");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   printf("\nEnter the element which you want to enter:");
   scanf("%d",&x);
   enqueue(x);
   break;
   case 2:
   res=dequeue();
   if(res==-1)
   printf("\nQueue is empty");
   else
   printf("\nThe element deleted from the queue is %d",res);
   break;
   case 3:
   res=IsEmpty();
   if(res==-1)
   printf("\nQueue is empty");
   else
   printf("\nQueue is not empty");
   break;
   case 4:
   res=IsFull();
   if(res==-1)
   printf("\nQueue is full");
   else
   printf("\nQueue is not full");
   break;
   case 5:
   display();
   break;
   case 6:
   exit(0);
   break;
  }}while(1);
 }  
   
   
   void enqueue(int x)
   {
    if(rear==max-1)
    {
     printf("\nQueue is full");
     return;
    }
    else
    {
     if(front==-1)
     {
      rear=0;
      front=0;
     }
     else
     rear=rear+1;
    queue[rear]=x;
   }
  }
  int dequeue()
  {
   int data;
   if(front==-1)
   return -1;
   else
   {
    data=queue[front];
    if(front==rear)
    {
     rear=-1;
     front=-1;
    }
    else
    front=front+1;
   }  
  return data;
 } 
  int IsEmpty()
  {
   if(front==-1)
   return -1;
  } 
  int IsFull()
  {
   if(rear==max-1)
   return -1;
  } 
  void display()
  {
   if(front==-1)
   {
    printf("\nQueue is empty");
    return;
   }
   else
   {
    for(int i=front;i<=rear;i++)
    {
     printf("%d ",queue[i]);
    }
   }
  }        
      
      
      
       
   
   
   
   
   
   
   
   
   
   
   
