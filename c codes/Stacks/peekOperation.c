#include<stdio.h>
#include<stdlib.h>

struct Stack{
int size;
int top;
int * arr;
};

int isFull(struct Stack *ptr){
  if(ptr->top==ptr->size-1){
    return 1;
  }
  else{
    return 0;
  }
}

int isEmpty(struct Stack * ptr){
      if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct Stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop  from the stack\n");
       return -1;
    }
    else{
      int val=ptr->arr[ptr->top];
      ptr->top--;
      return val;
    }
}

int peek(struct Stack *sp,int i){
    int arrayIndex=sp->top-i;
if(arrayIndex<0){
    printf("Not a Valid Position!");
    return -1;
}
else{
    return sp->arr[arrayIndex];
}
}

int main() {
struct Stack *sp=(struct Stack *) malloc(sizeof(struct Stack));
sp->size=10;
sp->top=-1;
sp->arr=(int *) malloc(sp->size * sizeof(int));
printf("Stack has been created succesfully\n");
printf("Before Pushing,Full:%d\n",isFull(sp));
printf("Before Pushing,Empty:%d\n",isEmpty(sp));

push(sp,1);
push(sp,2);
push(sp,3);
push(sp,4);
push(sp,5);
push(sp,6);
push(sp,7);
push(sp,8);
push(sp,9);
push(sp,10);//pushed 10 values
push(sp,11);//Stack Overflow since the size of the stack is 10

printf("After Pushing,Full: %d\n",isFull(sp));
printf("After Pushing,Empty: %d\n",isEmpty(sp));

printf("Popped %d drom the stack\n",pop(sp)); //Last in First Out
printf("Popped %d drom the stack\n",pop(sp));


for(int j=0;j<sp->top+1;j++){
printf("The Value at Index %d is %d\n",j,peek(sp,j));
}

return 0;
}