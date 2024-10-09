#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;
const ll INF = LONG_LONG_MAX;

/* Solucion: 
 * Bellman-Ford
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges;
    vector<ll> distance(n, 0);
    vector<int> parent(n, -1);

    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        edges.push_back({a, b, c});
    }

    int x = -1; // Perteneciente a un ciclo negativo, o alzancable desde él
    distance[0] = 0;
    forn(i, n){
        x = -1;
        for (auto [a, b, w] : edges) {
            if (distance[a]+w < distance[b]) {
                distance[b] = max(-INF, distance[a]+w);
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1){
        cout << "NO\n"; 
        return 0;
    }

    forn(i, n) {
        x = parent[x];
    }
    cout << "YES\n";
    vector<int> cycle;
    for (int v = x;; v = parent[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    for (int c : cycle) cout << c+1 << ' '; 
    cout << '\n';
 
    return 0;
}
