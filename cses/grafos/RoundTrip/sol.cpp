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
int cycle_start = -1;

bool dfs(int nodo, int prev = 0){
    cout << nodo+1 << endl;
    parent[nodo] = prev;
    if(visited[nodo]) {
        cycle_start = nodo;
        return true;
    }
    visited[nodo] = true;

    for(int adj : G[nodo]){
        if (adj == prev) continue;
        if (dfs(adj, nodo)) return true;
    }
    return false;
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

    bool have_cycle;
    forn(i, n){
        have_cycle = dfs(i);
        if (have_cycle) break;
    }
    cout << endl << cycle_start+1 << endl;

    if (!have_cycle){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> path;
    int next = parent[cycle_start];
    path.push_back(cycle_start+1);
    while(next != cycle_start){
        /*cout << "HOLA" << endl;*/
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
