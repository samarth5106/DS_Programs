#include <stdio.h>

int n, m;
int g[50][50];
int disc[50], low[50], visited[50];
int timeCounter = 0;
int hasArt = 0;

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    int child = 0;

    for (int v = 1; v <= n; v++) {
        if (g[u][v] == 0) continue;

        if (disc[v] == 0) {
            child++;
            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u])
                hasArt = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }

    if (parent == -1 && child > 1)
        hasArt = 1;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("Not Biconnected");
            return 0;
        }
    }

    if (hasArt)
        printf("Not Biconnected");
    else
        printf("Biconnected");

    return 0;
}
