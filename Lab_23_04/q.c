#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

void findPaths(int graph[MAX][MAX], int n, int src, int dest, int visited[], int path[], int pathIndex, int *shortest, int *longest)
{
    visited[src] = 1;
    path[pathIndex] = src;
    pathIndex++;

    if (src == dest)
    {
        int pathLength = 0;
        for (int i = 0; i < pathIndex - 1; i++)
        {
            pathLength += graph[path[i]][path[i + 1]];
        }

        if (pathLength < *shortest)
            *shortest = pathLength;
        if (pathLength > *longest)
            *longest = pathLength;

        if (pathLength != *shortest && pathLength != *longest)
        {
            printf("Path is: ");
            for (int i = 0; i < pathIndex; i++)
            {
                printf("%d ", path[i]);
            }
            printf("Length: %d\n", pathLength);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && graph[src][i] != 0)
            {
                findPaths(graph, n, i, dest, visited, path, pathIndex, shortest, longest);
            }
        }
    }

    pathIndex--;
    visited[src] = 0;
}

int main()
{
    int n, src, dest;
    int graph[MAX][MAX];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    int visited[MAX] = {0};
    int path[MAX];
    int shortest = INT_MAX, longest = INT_MIN;

    findPaths(graph, n, src, dest, visited, path, 0, &shortest, &longest);

    return 0;
}