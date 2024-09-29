#include <bits/stdc++.h>
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
    vector<bool> color(n, false);
    vector<bool> visited(n, false);

    forn(i, n){
        if (visited[i]) continue;
        q.push(i);
        while(!q.empty()){
            int n = q.front(); q.pop();
            visited[n] = true;

            for (int adj : G[n]) {
                if (!visited[adj]){
                    color[adj] = !color[n];
                    q.push(adj);
                }else if (color[adj] == color[n]){
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }

    forn(i, n) {
        cout << color[i] + 1 << " ";
    }
    cout << '\n';
 
    return 0;
}
