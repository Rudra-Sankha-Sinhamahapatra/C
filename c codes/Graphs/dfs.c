#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to perform Depth First Traversal
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[MAX_VERTICES], int numVertices) {
    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, numVertices);
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

    // Start DFS traversal from the first vertex
    printf("Depth First Traversal starting from vertex 0: ");
    DFS(graph, 0, visited, numVertices);
    printf("\n");

    return 0;
}
