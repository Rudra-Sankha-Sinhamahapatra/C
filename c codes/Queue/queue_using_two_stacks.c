//queue using two stacks

#include <stdio.h>
#include <stdlib.h>

// Define a structure for stack
struct Stack {
    int capacity;
    int top;
    int* array;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if a stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto a stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from a stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to enqueue an element into the queue
void enqueue(struct Stack* stack1, int item) {
    push(stack1, item);
}

// Function to dequeue an element from the queue
int dequeue(struct Stack* stack1, struct Stack* stack2) {
    if (isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            push(stack2, pop(stack1));
        }
    }

    if (isEmpty(stack2)) {
        printf("Queue is empty\n");
        return -1;
    }

    return pop(stack2);
}

int main() {
    // Create two stacks
    struct Stack* stack1 = createStack(10);  // For enqueue operation
    struct Stack* stack2 = createStack(10);  // For dequeue operation

    // Enqueue some elements
    enqueue(stack1, 1);
    enqueue(stack1, 2);
    enqueue(stack1, 3);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(stack1, stack2));
    printf("Dequeued: %d\n", dequeue(stack1, stack2));

    // Enqueue more elements
    enqueue(stack1, 4);
    enqueue(stack1, 5);

    // Dequeue remaining elements
    printf("Dequeued: %d\n", dequeue(stack1, stack2));
    printf("Dequeued: %d\n", dequeue(stack1, stack2));

    // Clean up allocated memory
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);

    return 0;
}