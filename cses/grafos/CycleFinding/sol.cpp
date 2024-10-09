#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;
const ll MAXN = 9999999999LL;

/* Solucion: 
 * Bellman-Ford
 * */

vector<bool> visited;

bool dfs(int nodo, vector<vector<int>> &adj, unordered_set<int> &cycle, stack<int> &path){
    if(visited[nodo]) return true;
    visited[nodo] = true;
    path.push(nodo);

    for(int b : adj[nodo]){
        if (!visited[b] && cycle.find(b) != cycle.end()){
            if(dfs(b, adj, cycle, path)) return true;
        }
        if (visited[b]) return true;
    }
    path.pop();
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    vector<vector<int>> adj(n);

    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
    }

    vector<ll> distance(n, MAXN);
    distance[0] = 0;

    forn(i, n-1){
        for (auto [a, b, w] : edges) {
            distance[b] = min(distance[b], distance[a]+w);
        }
    }

    // Guardamos los nodos que forman parte de un ciclo positivo
    int cycle_start = 1e6;
    unordered_set<int> cycle;
    for (auto [a, b, w] : edges) {
        if (distance[a]+w < distance[b]) {
            cycle.insert(a);
            cycle_start = min(cycle_start, a);
        }
        distance[b] = min(distance[b], distance[a]+w);
    }

    stack<int> path;
    visited.assign(n, false);
    bool have_path = dfs(cycle_start, adj, cycle, path);
    path.push(cycle_start);

    if (have_path){
        cout << "YES\n";
        vector<int> P;
        while(!path.empty()){
            int p = path.top(); path.pop();
            P.push_back(p+1);
        }
        reverse(P.begin(), P.end());
        for (int p : P) cout << p << ' '; 
        cout << '\n';
    }else{
        cout << "NO\n";
    }
 
    return 0;
}
