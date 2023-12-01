#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define QUEUE_SIZE 100

// Function to perform Breadth First Traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, bool visited[MAX_VERTICES], int numVertices) {
    int queue[QUEUE_SIZE];
    int front = -1, rear = -1;

    // Enqueue the starting vertex
    queue[++rear] = startVertex;
    visited[startVertex] = true;

    while (front != rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                // Enqueue the adjacent vertex if not visited
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Adjacency matrix to represent the graph
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    // Input the edges
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1; // Assuming an undirected graph
    }

    // Array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Start BFS traversal from the first vertex
    printf("Breadth First Traversal starting from vertex 0: ");
    BFS(graph, 0, visited, numVertices);
    printf("\n");

    return 0;
}
