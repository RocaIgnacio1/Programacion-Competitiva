#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000

/* Solucion: 
 * Buscar todas las componentes del grafo
 * De cada componente agarrar un elemento cualquiera
 * */

int last_component;
unordered_map<int, int> components;

int dfs(vector<vector<int>> &G, int n, int component=1){
    if (components.find(n) != components.end()) return components[n];
    components[n] = component;

    for (auto adj : G[n]) {
        if (components.find(adj) == components.end()) {
            dfs(G, adj, component);
        }
    }
    return component;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);

    forn(i, m){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    forn(i, n){
        dfs(G, i, i);
    }

    set<int> used;
    for (auto comp : components) {
        used.insert(comp.second);
    }
    cout << used.size() - 1 << '\n';
    for (auto it = used.begin(); next(it) != used.end(); it++) {
        cout << *it+1 << " " << *next(it)+1 << '\n';
    }
 
    return 0;
}
