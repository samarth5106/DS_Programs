#include <stdio.h>
int g[10][10];
int visited[10];
int q[10];
int f = 0, r = -1;
void bfs(int v, int n)
{
    int i;
    printf("BFS Traversal starting from vertex %d: ", v);

    visited[v] = 1;
    q[++r] = v;

    while(f <= r)
    {
        v = q[f++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(g[v][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
    printf("\n");
}
void dfs(int v, int n)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < n; i++)
    {
        if(g[v][i] && !visited[i])
            dfs(i, n);
    }
}
int main()
{
    int n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    printf("\nEnter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);
    printf("\n");
    bfs(start, n);

    for(i = 0; i < n; i++)
        visited[i] = 0;
    f = 0;
    r = -1;

    printf("DFS Traversal starting from vertex %d: ", start);
    dfs(start, n);
    printf("\n");

    return 0;
}

