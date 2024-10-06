#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef unsigned long long ll;
typedef pair<ll, ll> ii;

/* Solucion: 
 * Dijkstra
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<ii>> G(n);
    vector<bool> visited(n, false);

    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        G[a].push_back({b, c});
    }
 
    // La PQ esta ordenada de menor a mayor
    // Ordena por la primera componente por default
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<ll> distance(n, LONG_LONG_MAX);
    distance[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;

        for (auto [b, w] : G[a]) {
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({distance[b], b});
            }
        }
    }

    forn(i, n){
        cout << distance[i] << ' ';
    }
    cout << '\n';
    return 0;
}
