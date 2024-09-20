#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define MAXN 10001

struct Edge{
    int b;
    int value;
};

vector<Edge> adj[MAXN];

int main(){
    freopen("input.txt","r",stdin);

    int N, D;
    vector<int> R;
    cin >> N >> D;

    R.push_back(-1);
    forn(i, N){
        int r;
        cin >> r;
        R.push_back(r);
    }

    for(int i = 1; i <= N; i++){
        int s;
        cin >> s;
        if (s != -1){
            int value;
            if (R[s] == 0 && R[i] == 0) value = 0;
            if (R[s] == 0 && R[i] == 1) value = 1;
            if (R[s] == 1 && R[i] == 0) value = 2;
            if (R[s] == 1 && R[i] == 1) value = 3;

            adj[s].push_back(Edge{i, value});
        }
    }

    forn(i, N){
        cout << i << ": ";
        for (Edge e : adj[i]){
            cout << e.b << " w=" << e.value << ", ";
        }
        cout << endl;
    }

    vector<int> dist(MAXN, N+1);
    dist[1] = 0;
    forn(i, N-1){
        for(int j = 1; j < N; j++){
            if (dist[j] != MAXN){
                for (Edge e : adj[j]){
                    dist[e.b] = min(dist[e.b], dist[j]+e.value);
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << dist[i] << ", ";
    }
    cout << endl;

    bool cycles = true;
    forn(j, N){
        if (dist[j] != MAXN){
            for (Edge e : adj[j]){
                if (dist[e.b] > dist[j] + e.value){
                    cycles = true;
                }
            }
        }
    }

    return 0;
}