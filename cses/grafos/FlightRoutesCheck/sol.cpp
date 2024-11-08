#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;

const int MAXN = 1e5+1;

/* Solucion: 
 * Checkear si el grafo es fuertemente conexo
 * DFS para el grafo normal desde una arista cualquiera v (en este caso 1)
 * DFS en el grafo invertido desde la misma artista
 * Si existe arista sin visitar 'x' en algun dfs => "NO" v x 
 * */

int n, m;

vector<int> G[MAXN];
vector<int> G_inv[MAXN];

vector<bool> visited(MAXN, false);

void dfs(vector<int> *graph, int x){
    visited[x] = true;
    for(int i : graph[x]){
        if(!visited[i]) dfs(graph, i);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
    cin >> n >> m;

    forn(i, m){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G_inv[b].push_back(a);
    }

    dfs(G, 0);
    forn(i, n){
        if (!visited[i]){
            cout << "NO\n";
            cout << 1 << ' ' << i+1 << endl;
            return 0;
        }
    }
    /*cout << "reversed" << endl;*/
    fill(visited.begin(), visited.end(), false);
    dfs(G_inv, 0);
    forn(i, n){
        if (!visited[i]){
            cout << "NO\n";
            cout << i+1 << ' ' << 1 << endl;
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
