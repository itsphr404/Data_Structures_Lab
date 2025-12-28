#include <stdio.h>

int G[20][20], visited[20], q[20], n;
int f, r;

void bfs(int v) {
    f = 0;
    r = -1;
    q[++r] = v;
    visited[v] = 1;

    while (f <= r) {
        int curr = q[f++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (G[curr][i] && !visited[i]) {
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (G[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    // BFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    bfs(start);

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    dfs(start);

    return 0;
}
