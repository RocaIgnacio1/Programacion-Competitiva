#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef unsigned long long ll;
typedef pair<ll, int> ii;

const ll INF = 9999999999LL;

/* Solucion: 
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> G(n);

    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        G[a].push_back({b, c});
    }
 

    vector<ll> ans;
    forn(i, k){
        priority_queue<ii, vector<ii>, greater<ii>> q;
        vector<ll> distance(n, INF);
        vector<bool> visited(n, false);

        distance[0] = 0;
        q.push({0, 0});

        vector<int> parent(n, -1);
        while (!q.empty()) {
            int a = q.top().second; q.pop();
            assert(a >= 0 && a < n);
            if (visited[a]) continue;
            visited[a] = true;

            for (auto [b, w] : G[a]) {
                assert(b >= 0 && b < n);
                if (distance[a]+w < distance[b]) {
                    distance[b] = distance[a]+w;
                    parent[b] = a;
                    q.push({distance[b], b});
                }
            }
        }

        // Busco la arista del recorrido que tenga mayor peso
        ll max_w = 0;
        int max_a, max_b;
        for(int i = n-1; ;i = parent[i]){
            cout << i+1 << " ";
            if (i == 0) break;
            for (auto adj : G[parent[i]]){
                if (adj.first == i && adj.second > max_w){
                    max_a = parent[i];
                    max_b = i;
                    max_w = adj.second;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < G[max_a].size(); i++){
            if (G[max_a][i].first == max_b){
                G[max_a][i].second = INF;
            }
        }
        ans.push_back(distance[n-1]);
    }

    for (ll d : ans) cout << d << ' ';
    cout << '\n';

    return 0;
}
