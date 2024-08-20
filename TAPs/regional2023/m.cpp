#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define MAXN 100000
using namespace std;
typedef pair<int, int> ii;

using namespace std;

vector<pair<int, int>> G[MAXN]; //Lista de pares, dest, peso
bool visited[MAXN];
map<int, int> repe;

void dijkstra(int x, vector<int> &distance){
    // La PQ esta ordenada de menor a mayor
    priority_queue<ii, vector<ii>, greater<ii>> q;
    distance[x] = 0;
    q.push({0, x});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;

        for (auto u : G[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({distance[b], b});
            }else if (distance[a]+w == distance[b]){
                repe[b]++;
            }
        }
    }
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int N, M, P, Q;
    cin >> N >> M;
    cin >> P >> Q;

    forn(i, M){
        int u, v, d;
        cin >> u >> v >> d;

        G[u].push_back(make_pair(v, d));
        G[v].push_back(make_pair(u, d));
    }

    vector<int> dist(N+1, MAXN);
    dijkstra(P, dist);
    int d = dist[Q];

    bool no = false;
    forn(i, N+1){
        if (dist[i] == d * 2 && repe[i] == 0){
            cout << i << " ";
            no = true;
        }
    }
    
    if (!no){
        cout << "*";
    }
    cout << endl;
    
    return 0;
}