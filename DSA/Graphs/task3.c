#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

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
    G->adjacencyMatrix[dest][src] = 1;
    G->edges++;
}

void DFS(struct Graph* G, int vertex, int discoveryTime[], int low[], int parent[], int isArticulationPoint[]) {
    static int time = 0;
    int children = 0;

    discoveryTime[vertex] = low[vertex] = ++time;

    for (int i = 0; i < G->vertices; i++) {
        if (G->adjacencyMatrix[vertex][i] == 1) {
            if (discoveryTime[i] == -1) {
                children++;
                parent[i] = vertex;

                DFS(G, i, discoveryTime, low, parent, isArticulationPoint);

                low[vertex] = min(low[vertex], low[i]);
                
                if (parent[vertex] == -1 && children > 1) {
                    isArticulationPoint[vertex] = 1;
                } else if (parent[vertex] != -1 && low[i] >= discoveryTime[vertex]) {
                    isArticulationPoint[vertex] = 1;
                }
            } else if (i != parent[vertex]) {
                low[vertex] = min(low[vertex], discoveryTime[i]);
            }
        }
    }
}

void findArticulationPoints(struct Graph* G) {
    int discoveryTime[MAX_VERTICES];
    int low[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int isArticulationPoint[MAX_VERTICES];

    for (int i = 0; i < G->vertices; i++) {
        discoveryTime[i] = -1;
        low[i] = -1;
        parent[i] = -1;
        isArticulationPoint[i] = 0;
    }

    for (int i = 0; i < G->vertices; i++) {
        if (discoveryTime[i] == -1) {
            DFS(G, i, discoveryTime, low, parent, isArticulationPoint);
        }
    }

    printf("Articulation Points in the Graph:\n");
    for (int i = 0; i < G->vertices; i++) {
        if (isArticulationPoint[i]) {
            printf("%d\n", i);
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

    findArticulationPoints(&G);

    return 0;
}