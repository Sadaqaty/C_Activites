#include <stdio.h>
#include <limits.h>

#define N 5

void dijkstra(int graph[N][N], int start) {
    int dist[N];
    int visited[N] = {0};
    
    for (int i = 0; i < N; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    for (int i = 0; i < N - 1; i++) {
        int min_dist = INT_MAX, u;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("Distance from %d to %d is %d\n", start, i, dist[i]);
    }
}

int main() {
    int graph[N][N] = {
        {0, 10, 0, 0, 20},
        {10, 0, 50, 10, 0},
        {0, 50, 0, 20, 0},
        {0, 10, 20, 0, 60},
        {20, 0, 0, 60, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
