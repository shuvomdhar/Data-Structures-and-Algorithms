#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

char color[MAX_SIZE];
int parent[MAX_SIZE];
int d[MAX_SIZE];
int max = INT_MAX;

// Queue implementation for BFS
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue()
{
    int value;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        value = queue[front];
        front++;
        return value;
    }
}

bool isEmpty()
{
    return front == -1 || front > rear;
}

// Breadth First Search Algorithm
void BFS(int graph[MAX_SIZE][MAX_SIZE], int vertices, int start)
{
    for (int i = 0; i < vertices; i++)
    {
        color[i] = 'W';
        parent[i] = -1;
        d[i] = max;
    }
    bool visited[MAX_SIZE] = {false};
    visited[start] = true;
    color[start] = 'G';
    enqueue(start);
    d[start] = 0;
    printf("Breadth First Traversal starting from vertex %d: ", start);
    while (!isEmpty())
    {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                color[i] = 'G';
                parent[i] = current;
                d[i] = d[current] + 1;
                enqueue(i);
                visited[i] = true;
            }
        }
        color[current] = 'B';
    }
    printf("\n");
}

int main()
{
    int vertices, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    BFS(graph, vertices, start);
    printf("Colour array: ");
    for (int i = 0; i < vertices; ++i)
    {
        printf("%c ", color[i]);
    }
    printf("\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("Vertex: %d, ", i + 1);
        printf("Weight: %d, ", d[i]);
        printf("Parent: %d, ", parent[i]);
        printf("\n");
    }
    return 0;
}