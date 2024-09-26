#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000

/* Solucion: 
 * Comprobar si el grafo es bipartito
 * BFS pintando intercaladamente
 * */

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

    queue<int> q;
    vector<int> color(n, -1);

    q.push(0);
    dist[0] = 0;
    
    while(!q.empty()){
        int n = q.front(); q.pop();

        for (int adj : G[n]) {
            if (dist[adj] == -1) {
                dist[adj] = dist[n] + 1;
                parent[adj] = n;
                q.push(adj);
            }
        }
    }

    if (dist[n-1] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    return 0;
}
