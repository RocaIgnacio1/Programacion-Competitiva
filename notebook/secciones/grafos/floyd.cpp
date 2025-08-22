
/* minima distancia entre cada par de nodos en un grafo dirigido. 
    O(n^3)
*/
int dist[MAX_N][MAX_N]; //Distancia de i a j

// llenar la matriz de adjayencia
// tmb se podria armar a medida que lees la entrada
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == j) dist[i][j] = 0;
        else if (adj[i][j]) dist[i][j] = adj[i][j];
        else dist[i][j] = INF;
    }
}

/* After this, the shortest dists can be found as follows: */
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}
