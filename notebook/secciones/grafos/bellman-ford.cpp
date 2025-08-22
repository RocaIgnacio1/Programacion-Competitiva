#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector<tuple<int, int, int>> edges;
int n;

#define op min

// acepta negativos
// se puede cambiar a buscar el camino maximo cambiando
// min por max
void bellman_ford(int x){
    vector<int> dist(n, INF);
    dist[x] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a]+w);
        }
    }

    // Buscar ciclos negativos
    // Un ciclo que se reduce infinitamente
    unordered_set<int> in_cycle;
    for (auto [a, b, w] : edges) {
        if (dist[a]+w < dist[b]) {
            in_cycle.insert(b);
        }
        dist[b] = min(dist[b], dist[a]+w);
    }
}
