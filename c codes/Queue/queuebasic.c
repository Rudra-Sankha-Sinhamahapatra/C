#include<stdio.h>
int queue[5];
int front=-1;
int rear=-1;


int enqueue(int data){
    rear++;
     queue[rear]=data;
}
int dequeue(){
    front++;
   int x=queue[front];
    return x;
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("Data :- %d\n",queue[i]);
    }
}
int main() {
enqueue(3);
enqueue(2);
display();
dequeue();
printf("\n\ndisplaying after removing an element\n\n");
display();
return 0;
}