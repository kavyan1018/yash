#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initGraph(struct Graph* G, int vertices) {
    G->vertices = vertices;
    G->edges = 0;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            G->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* G, int src, int dest) {
    G->adjacencyMatrix[src][dest] = 1;
    G->edges++;
}

void DFS(struct Graph* G, int vertex, int visited[], int stack[], int* stackSize) {
    visited[vertex] = 1;

    for (int i = 0; i < G->vertices; i++) {
        if (G->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(G, i, visited, stack, stackSize);
        }
    }
    stack[(*stackSize)++] = vertex;
}

void DFSReverse(struct Graph* G, int vertex, int visited[], int component[]) {
    visited[vertex] = 1;
    component[vertex] = 1;

    for (int i = 0; i < G->vertices; i++) {
        if (G->adjacencyMatrix[i][vertex] == 1 && !visited[i]) {
            DFSReverse(G, i, visited, component);
        }
    }
}

void printSCC(struct Graph* G, int SCC[], int SCCSize) {
    printf("Strongly Connected Component: ");
    for (int i = 0; i < SCCSize; i++) {
        printf("%d ", SCC[i]);
    }
    printf("\n");
}

void stronglyConnectedComponents(struct Graph* G) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackSize = 0;

    for (int i = 0; i < G->vertices; i++) {
        if (!visited[i]) {
            DFS(G, i, visited, stack, &stackSize);
        }
    }
    for (int i = 0; i < G->vertices; i++) {
        visited[i] = 0;
    }
    struct Graph GT;
    initGraph(&GT, G->vertices);

    for (int i = 0; i < G->vertices; i++) {
        for (int j = 0; j < G->vertices; j++) {
            GT.adjacencyMatrix[j][i] = G->adjacencyMatrix[i][j];
        }
    }

    while (stackSize > 0) {
        int vertex = stack[--stackSize];

        if (!visited[vertex]) {
            int component[MAX_VERTICES] = {0};
            DFSReverse(&GT, vertex, visited, component);
            printSCC(G, component, G->vertices);
        }
    }
}

int main() {
    struct Graph G;
    int vertices, edges, src, dest;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    initGraph(&G, vertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&G, src, dest);
    }

    printf("Strongly Connected Components:\n");
    stronglyConnectedComponents(&G);

    return 0;
}