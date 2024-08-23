
/* minima distancia entre cada par de nodos en un grafo dirigido. 
    O(n^3)
*/
int distance[MAX_N][MAX_N];
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == j) distance[i][j] = 0;
        else if (adj[i][j]) distance[i][j] = adj[i][j];
        else distance[i][j] = INF;
    }
}

/* After this, the shortest distances can be found as follows: */

for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
        }
    }
}
