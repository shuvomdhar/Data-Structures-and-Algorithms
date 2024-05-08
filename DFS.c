#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 100

int graph[MAX][MAX];
char color[MAX];
int parent[MAX];
int visited[MAX];
int d[MAX], finish[MAX];
int max = INT_MAX;
int times = 0;

// Depth First Search Algorithm
void DFS(int graph[MAX][MAX], bool visited[MAX], int vertices, int start)
{
    printf("%d ", start);
    visited[start] = true;
    color[start] = 'G';
    d[start] = times++;
    for (int i = 0; i < vertices; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            parent[i] = start;
            DFS(graph, visited, vertices, i);
        }
    }
    color[start] = 'B';
    finish[start] = times++;
}

int main()
{
    int vertices, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        color[i] = 'W';
        parent[i] = -1;
    }
    bool visited[MAX] = {false};
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Depth First Traversal starting from vertex %d: ", start);
    DFS(graph, visited, vertices, start);
    printf("\nColor array is: ");
    for (int i = 0; i < vertices; ++i)
    {
        printf("%c ", color[i]);
    }
    printf("\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("Vertex:%d  ", i + 1);
        printf("Weight:%d  ", d[i] + 1);
        printf("final time:%d  ", finish[i] + 1);
        printf("Parent:%d  ", parent[i]);
        printf("\n");
    }
    return 0;
}