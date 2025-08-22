#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
typedef pair<int, int> ii;

vector<pair<int, int>> G[MAXN]; //Lista de pares, dest, peso
bool visited[MAXN];
int n;

void dijkstra(int x){
    // La PQ esta ordenada de menor a mayor
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<int> distance(n, MAXN);
    distance[x] = 0; // x es el punto de inicio
    q.push({0, x});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
 
        for (auto [b, w] : G[a]) {
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({distance[b], b});
            }
        }
    }
}
