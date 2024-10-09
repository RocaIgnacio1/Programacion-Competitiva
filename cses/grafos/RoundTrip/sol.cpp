#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000

/* Solucion: 
 * Buscar algun ciclo en el grafo
 * dfs => si encontras uno q ya visitaste hay un ciclo
 * */

vector<vector<int>> G;
vector<bool> visited;
vector<int> parent;

int dfs(int nodo, int prev = 0){
    parent[nodo] = prev;
    if(visited[nodo]) return nodo;
    visited[nodo] = true;

    for(int adj : G[nodo]){
        if (adj == prev) continue; // Para no volver para atras
        int cycle = dfs(adj, nodo);
        if (cycle != -1) return cycle;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    G.reserve(n);
    parent.reserve(n);
    visited.assign(n, false);

    forn(i, m){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int cycle_start = -1;
    forn(i, n){
        if (visited[i]) continue;
        cycle_start = dfs(i);
        if (cycle_start != -1) break;
    }

    if (cycle_start == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> path;
    int next = parent[cycle_start];
    path.push_back(cycle_start+1);
    while(next != cycle_start){
        path.push_back(next+1);
        next = parent[next];
    }
    path.push_back(cycle_start+1);

    cout << path.size() << '\n';
    for(int p : path){
        cout << p << ' ';
    }
    cout << '\n';
 
    return 0;
}
