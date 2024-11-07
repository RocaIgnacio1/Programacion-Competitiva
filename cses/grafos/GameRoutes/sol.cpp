#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef unsigned long long ll;
typedef pair<ll, int> ii;

const int MAXN = 1e5+1;
const int MOD = 1e9 + 7;

/* Solucion: 
 * Cantidad de caminos de 1 a n
 * Grafo dirigido sin ciclos (DAG)
 * DP[n], cantidad de caminos desde 1 a n
 * f(1) = 1
 * f(n) = for i in adj[n] caminos += f(i)
 * */

int n, m;
vector<int> G[MAXN];
vector<int> dp(MAXN, -1);

ll solve(int u) {
    /*cout << u+1 << endl;*/
    if (u == n-1) return 1;
    if (dp[u] != -1) return dp[u];

    ll res = 0;
    for (int v : G[u]) res = (res + solve(v)) % MOD;

    return dp[u] = res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
    cin >> n >> m;

    forn(i, m){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
    }

    /*dp[0] = 1;*/
    ll ans = solve(0);

    cout << ans << '\n';

    return 0;
}
