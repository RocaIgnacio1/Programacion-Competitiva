#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

const int MAXN = 2e5+1;

/* Solucion: 
 * DFS con DP
 * */

vector<int> adj[MAXN];
vector<int> subs(MAXN, 1);

void dfs(int n, int prev){
    for (auto u : adj[n]) {
        if (u == prev) continue;
        dfs(u, n);
        subs[n] += subs[u];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    forn(i, n-1){
        int u;
        cin >> u; u--;
        adj[u].push_back(i+1);
    }

    dfs(0, -1);

    forn(i, n){
        cout << subs[i]-1 << ' ';
    }
    cout << '\n';
 
    return 0;
}
