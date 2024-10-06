#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;
const ll MAXN = 9999999999LL;

/* Solucion: 
 * Bellman-Ford
 * Problema: cuando hay un ciclo positivo, pero no incluye el caminode desde 1 a n
 * */

vector<bool> bfs(int n, int src, vector<vector<int>> &adj){
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int b : adj[u]) {
            if (!visited[b]) {
                visited[b] = true;
                q.push(b);
            }
        }
    }
    return visited;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    vector<vector<int>> adj(n);
    vector<vector<int>> adj_inv(n);

    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
        adj_inv[b].push_back(a);
    }

    vector<ll> distance(n, -MAXN);
    distance[0] = 0;

    forn(i, n-1){
        for (auto [a, b, w] : edges) {
            distance[b] = max(distance[b], distance[a]+w);
        }
    }

    // Guardamos los nodos que forman parte de un ciclo positivo
    unordered_set<int> in_cycle;
    for (auto [a, b, w] : edges) {
        if (distance[a]+w > distance[b]) {
            in_cycle.insert(b);
        }
        distance[b] = max(distance[b], distance[a]+w);
    }

    // Guardamos los nodos q podemos alcanzar desde 1 y los que podemos alcanzar desde n
    vector<bool> reacheable_from_1 = bfs(n, 0, adj);
    vector<bool> reacheable_from_n = bfs(n, n-1, adj_inv);

    bool infinite = false;
    for(int c : in_cycle){
        if (reacheable_from_1[c] && reacheable_from_n[c]) infinite = true;
    }

    if(infinite){
        cout << -1 << '\n';
    }else{
        cout << distance[n - 1] << '\n';
    }
 
    return 0;
}
