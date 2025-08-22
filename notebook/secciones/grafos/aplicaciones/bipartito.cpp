#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000

/* Comprobar si el grafo es bipartito
 * BFS pintando intercaladamente
 * */

int main(){
    int n, m; 
    // Leer el grafo
    vector<vector<int>> G(n);

    queue<int> q;
    vector<int> color(n, -1);

    forn(i, n){
        if (color[i] != -1) continue;

        q.push(i); color[i] = 0;
        while(!q.empty()){
            int n = q.front(); q.pop();

            for (int adj : G[n]) {
                if (color[adj] == -1){
                    color[adj] = color[n] ^ 1; // invertir, si es 1 => 0, 0 => 1
                    q.push(adj);
                }else if (color[adj] == color[n]){
                    cout << "IMPOSSIBLE\n"; // no es bipartito
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
