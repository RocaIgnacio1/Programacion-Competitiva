// https://cses.fi/problemset/task/1669/
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000

vector<vector<int>> G;
vector<bool> visited;
vector<int> parent;

// buscamos algun ciclo
int dfs(int nodo, int prev = 0){
    parent[nodo] = prev;
    if(visited[nodo]) return nodo;
    visited[nodo] = true;

    for(int adj : G[nodo]){
        if (adj == prev) continue; // Para no volver para atras
        int cycle = dfs(adj, nodo);
        if (cycle != -1) return cycle; // si hay ciclo
    }
    return -1; // si no ahay ciclo devuelve -1
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;

    // leer grafo

    int cycle_start = -1;
    forn(i, n){
        if (visited[i]) continue; // si ya esta visitado, ya forma parte d un ciclo
        cycle_start = dfs(i);
        if (cycle_start == -1){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    
    // reconstruir camino
    vector<int> path;
    int next = parent[cycle_start];
    path.push_back(cycle_start+1);
    while(next != cycle_start){
        path.push_back(next+1);
        next = parent[next];
    }
    path.push_back(cycle_start+1);

    // mostrar path
}
