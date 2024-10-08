#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int MAXN = 100001;
const ll INF = 1e10-1;

vector<ii> G[MAXN]; 
vector<bool> visited;

void dijkstra(int x, vector<ll> &distance, int skip=-1){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    distance[x] = 0;
    q.push({0, x});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;

        for (auto u : G[a]) {
            int b = u.first;
            ll w = u.second;
            if (b == skip) continue;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({distance[b], b});
            }        
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, P, Q;
    cin >> N >> M;
    cin >> P >> Q;

    forn(i, M){
        int u, v;
        ll d;
        cin >> u >> v >> d;

        G[u].push_back(make_pair(v, d));
        G[v].push_back(make_pair(u, d));
    }

    vector<ll> dist_1(N+1, INF);
    vector<ll> dist_2(N+1, INF);
    visited.assign(N+1, false);
    dijkstra(P, dist_1);
    visited.assign(N+1, false);
    dijkstra(P, dist_2, Q);

    bool possible = false;
    forn(i, N+1){
        if ((dist_1[i] == dist_1[Q] * 2) && (dist_2[i] > dist_1[i])){
            cout << i << " ";
            possible = true;
        }
    }
    
    if (!possible){
        cout << "*";
    }
    cout << '\n';
    
    return 0;
}
