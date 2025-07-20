#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 200100;

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> G(n+1);
    vector<bool> busy(n+1, false);
    forn(i, k){
        int a; cin >> a; a--;
        busy[a] = true;
    }
    forn(i, m){
        int p, q; cin >> p >> q; p--; q--;
        if (!busy[p]) G[p].pb(q);
        if (!busy[q]) G[q].pb(p);
    }

    queue<int> q;
    vector<bool> visited(n+1, false);
    vector<bool> invited(n+1, false);
    vector<vector<int>> inv(n+1);
    forn(i, n){
        if (!busy[i]){ q.push(i); break; }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        visited[u] = true;
        if (busy[u]) continue; // no invito a nadie

        for (int adj : G[u]) {
            if (!visited[adj] && !invited[adj]){
                invited[adj] = true;
                q.push(adj);
                inv[u].pb(adj);
            }
        }
    }

    int inviteds = 1;
    int steps = 0;
    forn(i, n){
        if (inv[i].size() > 0) {
            inviteds += inv[i].size();
            steps ++;
        }
    }
     

    if (inviteds == n) {
        cout << "Yes" << endl;
        cout << steps << endl;
        forn(i, n){
            if (inv[i].size() > 0){
                cout << i+1 << ' ' << inv[i].size() << ' ';
                for(auto v : inv[i]) cout << v+1 << ' ';
                cout << endl;
            }
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}