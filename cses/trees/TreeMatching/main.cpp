#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
// #define dbg(x) cerr << #x << ": " << x << endl;
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
#ifdef EBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
template<typename T> void debug_out(T x) { cerr << ' ' << x << '\n'; }
template<typename T, typename... Args> void debug_out(T x, Args... args) {
    cerr << ' ' << x; debug_out(args...);
}
#else
#define dbg(...) 0
#endif

const int MAXN = 2*1e5+1;

vector<int> G[MAXN];
bool used[MAXN];
int ans = 0;

void dfs(int s, int p){
    int m = 0;
    for(auto adj : G[s]){
        if (adj == p) continue;
        dfs(adj, s);
        // cout << adj+1 << ' ' << m << endl;
        // dbg(m);
        // dbg(adj+1, !taked, m);
    }
    if (!used[p] && !used[s] && p != -1){
        used[p] = true;
        used[s] = true;
        ans++;
    }
}

int main(){
    HOLA

    int n;
    cin >> n;

    forn(i, n-1){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1);
    cout << ans << '\n';
 
    return 0;
}
