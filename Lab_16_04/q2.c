#include <stdio.h>
#include <stdbool.h>

#define V 5

bool isSafe(int v, int pos, int path[], int graph[][V])
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

void hamiltonianPathUtil(int graph[][V], int path[], int pos)
{
    if (pos == V)
    {
        for (int i = 0; i < V; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, pos, path, graph))
        {
            path[pos] = v;

            hamiltonianPathUtil(graph, path, pos + 1);

            path[pos] = -1; // Backtrack
        }
    }
}

void findAllHamiltonianPaths(int graph[][V])
{
    int path[V];

    for (int i = 0; i < V; i++)
    {
        path[i] = -1;
    }

    path[0] = 0;

    hamiltonianPathUtil(graph, path, 1);
}

int main()
{
    int graph[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}};

    printf("All Hamiltonian Paths:\n");
    findAllHamiltonianPaths(graph);

    return 0;
}
