#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef unsigned long long ll;
typedef tuple<ll, int, bool> e;

/* Solucion: 
 * Dijkstra modificado
 * Tenemos en cuenta dos estados diferentes para cada ciudad, uno habiendo usado el cupon y otro sin
 * Para cada vuelo, si no usamos el cupón, tenemos dos opciones:
    - Usar el vuelo al costo original y no usar el cupón.
    - Usar el cupón en ese vuelo, reduciendo su costo a ⌊w/2⌋.
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> G(n);
    vector<vector<bool>> visited(n, vector<bool>(2, false));

    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        G[a].push_back({b, c});
    }
 
    priority_queue<e, vector<e>, greater<e>> q;

    // distance[0][i] => sin usar el cupon, distance[1][i] => usando el cupon
    vector<vector<ll>> distance(2, vector<ll>(n, LONG_LONG_MAX));
    distance[0][0] = 0;
    q.push({0, 0, false}); // distance, v, si ya aplique el descuento

    while (!q.empty()) {
        auto [dist, a, discount] = q.top(); q.pop();
        if (visited[a][discount]) continue;
        visited[a][discount] = true;

        for (auto [b, w] : G[a]) {
            // NO aplicar el descuento
            if (distance[discount][a]+w < distance[discount][b]) {
                distance[discount][b] = distance[discount][a]+w;
                q.push({distance[discount][b], b, discount});
            }

            // Aplicar el descuento
            if (!discount){
                ll w2 = w/2;
                if (distance[0][a]+w2 < distance[1][b]) {
                    distance[1][b] = distance[0][a]+w2;
                    q.push({distance[1][b], b, true});
                }
            }
        }
    }

    cout << min(distance[0][n-1], distance[1][n-1]) << '\n';
    return 0;
}
