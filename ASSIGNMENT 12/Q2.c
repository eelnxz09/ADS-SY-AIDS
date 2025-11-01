#include <stdio.h>
#include <stdlib.h>
#define V 5

struct Node {
    int dest;
    struct Node *next;
};

struct Graph {
    struct Node *adj[V];
};

struct Node* newNode(int dest) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->dest = dest;
    temp->next = NULL;
    return temp;
}

struct Graph* createGraph() {
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *temp = newNode(dest);
    temp->next = graph->adj[src];
    graph->adj[src] = temp;

    temp = newNode(src);
    temp->next = graph->adj[dest];
    graph->adj[dest] = temp;
}

void printGraph(struct Graph *graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);
        struct Node *temp = graph->adj[i];
        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph();

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printGraph(graph);
    return 0;
}
