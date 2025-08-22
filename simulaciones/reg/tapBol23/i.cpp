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
const ll MAXN = 1e5+1;
const int MOD = 1e9+7;

vector<int> G[MAXN];
int comp[MAXN];
map<int, int> g;

int dfs(int n, int component=1){
    if (comp[n] != -1) return comp[n];
    comp[n] = component;
    g[comp[n]] += 1;

    for (auto adj : G[n]) {
        //cout << n << ' ' << adj << endl;
        //cout << comp[n] << endl;
        dfs(adj, component);
        if (comp[adj] == -1) {
        }
        //cout << comp[adj] << endl;
    }
    return component;
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("i.txt", "r", stdin);
    #endif

    int n, m; cin >> n >> m;    
    forn(i, m) {
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    memset(comp, -1, sizeof(comp));
    forn(i, n){
        dfs(i, i+1);
    }

    ll ans = 1;
    for (auto it : g) {
        ans = ((ans%MOD) * it.second) % MOD;
    }

    cout << ans << endl;

    return 0;
}