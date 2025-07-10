#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

/* Solucion: 
 * Buscar algun ciclo en el grafo
 * dfs => si encontras uno q ya visitaste hay un ciclo
 * Problema: Esta solucion usa demasiada memoria O(n)
 * */

vector<vector<int>> G;
vector<bool> visited;
vector<int> parent;

int dfs(int nodo){
    if(visited[nodo]) return nodo;
    visited[nodo] = true;

    for(int adj : G[nodo]){
        parent[adj] = nodo;
        int cycle = dfs(adj);
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
    }

    int cycle_start = -1;
    forn(i, n){
        if (visited[i]) continue;
        cycle_start = dfs(i);
        if (cycle_start != -1) break;
    }
    /*cout << "start: " << cycle_start+1 << endl;*/
    /*cout << "p: " << parent[cycle_start]+1 << endl;*/
    /*cout << "p: " << parent[1]+1 << endl;*/
    /*cout << "p: " << parent[2]+1 << endl;*/

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
        /*cout << next+1 << endl;*/
    }
    path.push_back(cycle_start+1);
    // Hacemos reverse porque el grafo es dirigido
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for(int p : path){
        cout << p << ' ';
    }
    cout << '\n';
 
    return 0;
}
