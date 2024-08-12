#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

#define MAXN 101

//#define DEBUG
#ifdef DEBUG
    #define DBG(x) x
#else
    #define DBG(x)
#endif

struct Nodo{
    int b;
    int c;
};
vector<Nodo> adj[MAXN];
vector<bool> visited(MAXN, false);

bool dfs(int a, int b, int color) {
    visited[a] = true;
    if (a == b) return true;
    bool path = false;

    for (Nodo n: adj[a]){
        if (!visited[n.b]){
            if (n.c == color){
                DBG(cout << a << " -> " << n.b << " C: " << n.c << endl;)
                path |= dfs(n.b, b, n.c);
            }
        }    
    }
    return path;
}

int main() {
    DBG(freopen("input.txt", "r", stdin);)
    int n, m, q;
    cin >> n >> m;

    forn(i, m){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(Nodo{b, c});
        adj[b].push_back(Nodo{a, c});
    }
    cin >> q;

    forn(i, q){
        int u, v;
        cin >> u >> v;
        int paths = 0;
        forn(j, m){
            if (dfs(u, v, j+1)){
                paths += 1;
                DBG(cout << u << " conected " << v << " color: " << j+1 << endl;)
            }            
            visited.assign(MAXN, false);
        }
        cout << paths << endl;
    }

    return 0;
}
