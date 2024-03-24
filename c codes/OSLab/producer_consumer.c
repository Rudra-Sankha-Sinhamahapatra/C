#include<stdio.h>

int mutex = 1;
int empty;
int full = 0;

int n;
int buffer[100];
int front = 0;
int rear = 0;

void wait(int *s){
    while(*s<=0);
    (*s)--;
}

void signal(int *s){
    (*s)++;
}

void producer(int item){
        /* Item produced */
        wait(&empty);
        wait(&mutex);

        buffer[rear] = item;
        printf("\nProduced item is: %d", item);
        rear = (rear+1)%n;

        signal(&mutex);
        signal(&full);
}

void consumer(){
        wait(&full);
        wait(&mutex);

        int item = buffer[front];
        printf("\nConsumed item is: %d", item);
        front = (front+1)%n;

        signal(&mutex);
        signal(&empty);
        /* Item consumed */
}

int main(){
    printf("\nEnter n: ");
    scanf("%d", &n);
    empty = n;

    producer(1);
    printf("\nFull = %d", full);
    printf("\nEmpty = %d", empty);
    producer(2);
    printf("\nFull = %d", full);
    printf("\nEmpty = %d", empty);
    producer(3);
    printf("\nFull = %d", full);
    printf("\nEmpty = %d", empty);
    consumer();
    printf("\nFull = %d", full);
    printf("\nEmpty = %d", empty);
    consumer();
    printf("\nFull = %d", full);
    printf("\nEmpty = %d", empty);

    return 0;
}