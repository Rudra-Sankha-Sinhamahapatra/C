// 6.1 Write a menu driven program to create a stack using array and perform the following operation using
// function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements
// Sample Input/Output:
// Main Menu
// 1. Push
// 2. Pop
// 3. IsEmpty
// 4. IsFull
// 5. Traverse
// 6. Exit
// Enter option: 1
// Enter element to be pushed into the stack: 22
// Enter option: 1
// Enter element to be pushed into the stack: 33
// Enter option: 1
// Enter element to be pushed into the stack: 44
// Enter option: 1
// Enter element to be pushed into the stack: 88
// Enter option: 1
// Enter element to be pushed into the stack: 66
// Enter option: 5
// Stack: 66 88 44 33 22
// Enter option: 2
// 66 deleted from Stack
// Enter option: 3
// Stack empty: False

#include <stdio.h>
#include <stdlib.h>
#define max 10
int top=-1;
int stack[max];
void push(int element);
int pop();
int isEmpty();
int isFull();
void display();
int main()
{
 do{
 int ch,element,res;
 printf("\n1.Push");
 printf("\n2.Pop");
 printf("\n3.IsEmpty");
 printf("\n4.IsFull");
 printf("\n5.Display");
 printf("\n6.Exit");
 printf("\nEnter the choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
  printf("\nEnter the element which you want to push:");
  scanf("%d",&element);
  push(element);
  break;
  case 2:
  res=pop();
  if(res==-1)
  printf("Stack Underflow\n");
  else
  printf("The element deleted is %d\n",res);
  break;
  case 3:
  res=isEmpty();
  if(res==-1)
  printf("The stack is empty\n");
  else
  printf("The stack is not empty\n");
  break;
  case 4:
  res=isFull();
  if(res==-1)
  printf("The stack is full\n");
  else
  printf("The stack is not full\n");
  break;
  case 5:
  printf("The Elements in the Stack:\t");
  display();
  break;
  case 6:
  exit(0);
  break;
  default:
  printf("Wrong choice entered\n");
  break;
 } 
 }while(1);
 }
 void push(int element)
 {
  if(top==max-1)
  {
  printf("Stack Overflow\n");
  return;
  }
  top++;
  stack[top]=element;
 } 
  int pop()
  {
   if(top==-1)
   return -1;
   else
   {
   int res=stack[top];
    top--;
    return res;
   }
  }
  int isEmpty()
  {
   return top;
  } 
  int isFull()
  {
   if(top==max-1)
   return -1;
   else
   return 0;
  }   
  void display()
  {
   if(top==-1)
   {
    printf("Empty Stack\n");
   }
   else
   { 
   for(int i=0;i<=top;i++)
   {
    printf("%d ",stack[i]);
   }
   }
  }  
  
  
    
    
  
  
  
   
