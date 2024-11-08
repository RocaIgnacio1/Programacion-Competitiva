#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define MAXN 1000000

/* Buscar todas las componentes del grafo
 * De cada componente agarrar un elemento cualquiera
 * */

vector<int> G[MAXN];
int components[MAXN]; //LLenar en -1

int dfs(int n, int component=1){
    if (components[n] != -1) return components[n];
    components[n] = component;

    for (auto adj : G[n]) {
        if (components[n] == -1) {
            dfs(adj, component);
        }
    }
    return component;
}

int main(){
    int n, m; //Leer el grafo

    forn(i, n){
        dfs(i, i);
    }

    return 0;
}
