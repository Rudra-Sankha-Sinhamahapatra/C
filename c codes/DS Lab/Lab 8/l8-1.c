// 8.1 Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) and
// performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.
// Sample Input/Output:
// Input restricted Dequeue Menu
// 1. Insert at right
// 2. Delete from left
// 3. Delete from right
// 4. Display
// 5.Quit
// Enter choice: 1
// Enter element:87
// Enter choice: 1
// Enter element:32
// Enter choice: 4
// Deque: 87 32
// Enter choice: 2
// 87 deleted
// Enter choice: 4
// Deque: 32

#include <stdio.h>
#define max 4
#include <stdlib.h>
int left=-1;
int right=-1;
int queue[max];
void insert_right(int x);
void insert_left(int x);
int delete_left();
int delete_right();
void traverse();
int main()
{
 int ch,x,res;
 do
 {
 printf("\n1.Insert at right");
 printf("\n2.Insert at left");
 printf("\n3.Delete from left");
 printf("\n4.Delete from right");
 printf("\n5.Display");
 printf("\n6.Quit");
 printf("\nEnter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
  printf("\nEnter the element which you want to insert:");
  scanf("%d",&x);
  insert_right(x);
  break;
  case 2:
  printf("\nEnter the element which you want to insert:");
  scanf("%d",&x);
  insert_left(x);
  break;
  case 3:
  res=delete_left();
  if(res==-1)
  printf("Queue is empty");
  else
  printf("The element deleted from the queue is %d",res);
  break;
  case 4:
  res=delete_right();
  if(res==-1)
  printf("Queue is empty");
  else
  printf("The element deleted from the queue is %d",res);
  break;
  case 5:
  traverse();
  break;
  case 6:
  exit(0);
  break;
  default:
  printf("\nWrong Input");
  break;
 }}while(1); 
}  
  
  
  
  
  
  
  
  void insert_right(int x)
  {
   if((left==0&&right==max-1)||(left==right+1))
   {
    printf("\nQueue is full");
    return;
   }
   else
   {
    if(left==-1)
    {
     left=0;
     right=0;
    }
    else if(right==max-1&&left!=0)
    {
     right=0;
    }
    else
    right++;
    queue[right]=x;
   }
  }     
  
  int delete_left()
  {
   int val;
   if(left==-1)
   return -1;
   else
   {
    val=queue[left];
    if(left==right)
    {
     left=-1;
     right=-1;
    }
    else if(left==max-1)
    left=0;
    else
    left=left+1;
   }
   return val;
  }  
  int delete_right()
  {
   int val;
   if(left==-1)
   return -1;
   else
   {
    val=queue[right];
    if(left==right)
    {
     left=-1;
     right=-1;
    }
    else if(right==0)
    right=max-1;
    else
    right=right-1;
   }
   return val;
  }  
  void traverse()
  {
   if(left==-1)
   {
    printf("\nQueue is empty");
    return;
   }
   printf("\n");
   if(left<right)
   {
    for(int i=left;i<=right;i++)
    {
     printf("%d ",queue[i]);
    }  
   }
   else
   {
    for(int i=left;i<max;i++)
    {
    printf("%d ",queue[i]);
    }
    for(int i=0;i<=right;i++)
    {
    printf("%d ",queue[i]);
   }
   }
  }  
  void insert_left(int x)
  {
   if((left==0&&right==max-1)||(left==right+1))
   {
    printf("\nQueue is full");
    return;
   }
   else
   {
    if(left==-1)
    {
     left=0;
     right=0;
    }
    else if(left==0)
    {
     left=max-1;
    }
    else
    left=left-1;
    queue[left]=x;
   }
  }     
  
  
  
  
  
  
