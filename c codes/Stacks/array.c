//implementing stack using array
#include<stdio.h>
#include<stdlib.h>

struct Stack{
int size;
int top;
int * arr;
};
int isEmpty(struct Stack *ptr){
if(ptr->top==ptr->size-1){
    return 1;
}
else{
    return 0;
}
}

int main() {
// struct Stack s;
// s.size=80;
// s.top=-1;
// s.arr= (int *) malloc (s.size * sizeof(int));
struct Stack *s;
s->size=80;
s->top=-1;
s->arr= (int *) malloc (s->size * sizeof(int));

//pushing an element manually
s->arr[0]=4;
s->top++;


//check if stack is empty
if(isEmpty(s)){
    printf("Stack is Empty\n");
}
else{
    printf("Stack is not Empty\n");
}
return 0;
}