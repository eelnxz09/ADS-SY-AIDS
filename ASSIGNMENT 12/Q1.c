#include <stdio.h>
#define V 5

void init(int arr[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void insertEdge(int arr[V][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1; // because graph is undirected
}

void printAdjMatrix(int arr[V][V]) {
    int i, j;
    printf("   ");
    for (i = 0; i < V; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < V; i++) {
        printf("%d  ", i);
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];
    init(adjMatrix);

    insertEdge(adjMatrix, 0, 1);
    insertEdge(adjMatrix, 0, 2);
    insertEdge(adjMatrix, 0, 3);
    insertEdge(adjMatrix, 2, 0);
    insertEdge(adjMatrix, 2, 3);
    insertEdge(adjMatrix, 1, 3);
    insertEdge(adjMatrix, 0, 4);
    insertEdge(adjMatrix, 2, 4);

    printAdjMatrix(adjMatrix);
    return 0;
}
