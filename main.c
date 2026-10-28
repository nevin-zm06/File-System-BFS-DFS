#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start, int target)
{
    int queue[MAX], front = 0, rear = 0;
    int i, found = 0;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        if (current == target)
            found = 1;

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFS(int current, int target, int *found)
{
    int i;

    visited[current] = 1;
    printf("%d ", current);

    if (current == target)
        *found = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
            DFS(i, target, found);
    }
}

int main(void)
{
    int i, j, start, target, found;

    printf("Enter number of nodes (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter the %d x %d adjacency matrix (0 or 1):\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (scanf("%d", &graph[i][j]) != 1 ||
                (graph[i][j] != 0 && graph[i][j] != 1))
            {
                printf("Invalid matrix value. Use only 0 or 1.\n");
                return 1;
            }
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= n)
    {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter target file node (0 to %d): ", n - 1);
    if (scanf("%d", &target) != 1 || target < 0 || target >= n)
    {
        printf("Invalid target node.\n");
        return 1;
    }

    BFS(start, target);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    found = 0;
    printf("\nDFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
