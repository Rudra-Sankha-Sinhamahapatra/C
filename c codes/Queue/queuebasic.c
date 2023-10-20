#include<stdio.h>
int queue[5];
int front=-1;
int rear=-1;


int enqueue(int data){
    rear++;
     queue[rear]=data;
}
int dequeue(){
    int x=queue[front];
    front++;
    return x;
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("Data :- %d\n",queue[i]);
    }
}
int main() {
dequeue();
enqueue(3);
enqueue(2);
display();
dequeue();
printf("\n\ndisplaying after removing an element\n\n");
display();
return 0;
}