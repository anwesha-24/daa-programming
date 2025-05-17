#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the cost adjacency matrix of MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    int mstCostMatrix[V][V] = {0};  // Initialize MST cost adjacency matrix with 0

    // Build the MST cost adjacency matrix from the parent array
    for (int i = 1; i < V; i++) {
        mstCostMatrix[i][parent[i]] = graph[i][parent[i]];
        mstCostMatrix[parent[i]][i] = graph[i][parent[i]];
    }

    // Print the MST cost adjacency matrix
    printf("Cost adjacency matrix of the MST:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (mstCostMatrix[i][j] == 0) {
                printf("INF\t");  // No edge in MST
            } else {
                printf("%d\t", mstCostMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V];    // Array to store constructed MST
    int key[V];       // Key values used to pick minimum weight edge in cut
    bool mstSet[V];   // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    key[0] = 0;       // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;   // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST's cost adjacency matrix
    printMST(parent, graph);
}

int main() {
    /* Example graph represented by an adjacency matrix
       INF represents no edge between nodes */
    int graph[V][V] = {
        { 0, 2, INF, 6, INF },
        { 2, 0, 3, 8, 5 },
        { INF, 3, 0, INF, 7 },
        { 6, 8, INF, 0, 9 },
        { INF, 5, 7, 9, 0 }
    };

    // Print the MST cost adjacency matrix
    primMST(graph);

    return 0;
}
