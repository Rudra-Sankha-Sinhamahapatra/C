#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

struct Stack {
    int capacity;
    int top;
    int* array;
};

struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
struct Stack* createStack(int capacity);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);
void topologicalSortUtil(struct Graph* graph, int vertex, int visited[MAX_VERTICES], struct Stack* stack);
void topologicalSort(struct Graph* graph);

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Topological Sort: ");
    topologicalSort(graph);

    return 0;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1; // Return a special value to indicate an empty stack
    return stack->array[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void topologicalSortUtil(struct Graph* graph, int vertex, int visited[MAX_VERTICES], struct Stack* stack) {
    visited[vertex] = 1;

    struct Node* currentNode = graph->adjacencyList[vertex];
    while (currentNode != NULL) {
        int adjacentVertex = currentNode->data;
        if (!visited[adjacentVertex]) {
            topologicalSortUtil(graph, adjacentVertex, visited, stack);
        }
        currentNode = currentNode->next;
    }

    // All adjacent vertices are processed, push the current vertex to the stack
    push(stack, vertex);
}

void topologicalSort(struct Graph* graph) {
    struct Stack* stack = createStack(graph->numVertices);
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    // Print the contents of the stack to get the topological order
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}
