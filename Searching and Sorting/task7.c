#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void topologicalSortUtil(struct Graph* graph, int vertex, int visited[], struct Node** stack) {
    visited[vertex] = 1; 

    struct Node* current = graph->adjacencyList[vertex];
    while (current != NULL) {
        if (!visited[current->data]) {
            topologicalSortUtil(graph, current->data, visited, stack);
        }
        current = current->next;
    }

    struct Node* newNode = createNode(vertex);
    newNode->next = *stack;
    *stack = newNode;
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    struct Node* stack = NULL;

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, &stack);
        }
    }

    printf("Topological Order:\n");
    while (stack != NULL) {
        printf("%d ", stack->data);
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }

    free(visited);
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    free(graph->adjacencyList);
    free(graph);

    return 0;
}