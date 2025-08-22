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

const int MAXN = 5*1e4+10;

int s[MAXN];
int pc[MAXN]; // parent count
int pr[MAXN]; // parent registereds
vector<int> G[MAXN];

int register_nodes(int i){
    //cout << "visiting:" << i << ' ' << s[i] << endl;
    if (pr[i] != pc[i]) return 0;
    if (s[i] == 0) return 0;
    if (s[i] == 1) s[i] = 2;
    //cout << pr[i] << " == " << pc[i] << endl;
 
    int c = 1;
    for(int adj : G[i]){
        pr[adj] += 1;
        //cout << "adj: " << adj << endl;
        
        c += register_nodes(adj);
        // s[adj] = 2;
    }

    return c;
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("c.in", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    forn(i, n+1){
        pc[i] = 0;
    }
    s[0] = 2;
    G[0].pb(1);
    pc[1] = 1;
    pr[1] = 1;
    forn(i, m){
        int a, b; cin >> a >> b;
        G[a].pb(b);
        pc[b] += 1;
    }

    int ans = 0;
    forn(i, n){
        int p; cin >> p;

        s[p] = 1;
        int rn = register_nodes(p);
        //cout << "rn: " << rn << endl;
        ans += rn;

        cout << ans << endl;
    }
    
    return 0;
}