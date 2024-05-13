#include <stdio.h>
#include <limits.h>
#define MAX 100

// Function to perform Floyd-Warshall algorithm
void floydWarshall(int graph[MAX][MAX], int vertices)
{
    int distance[MAX][MAX];
    int i, j, k;
    // Initialize distance matrix same as input graph matrix
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            distance[i][j] = graph[i][j];
        }
    }

    // Compute shortest paths
    for (k = 0; k < vertices; k++)
    {
        for (i = 0; i < vertices; i++)
        {
            for (j = 0; j < vertices; j++)
            {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX && distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if (distance[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", distance[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix for the graph (-1 for infinity):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) // assuming -1 for INF
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    floydWarshall(graph, vertices);
    return 0;
}