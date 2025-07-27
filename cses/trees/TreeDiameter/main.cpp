#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
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
int to_leaf[MAXN];
int max_len[MAXN];

void dfs(int s, int p){
    to_leaf[s] = 0;
    int first = 0, second = 0; // Mas grande y segundo mas grande, maximizan la suma
    for(auto adj : G[s]){
        if (adj == p) continue;
        dfs(adj, s);
        to_leaf[s] = max(to_leaf[adj] + 1, to_leaf[s]);
        if (to_leaf[adj] >= first){
            second = first;
            first = to_leaf[adj];
        }else if(to_leaf[adj] >= second){
            second = to_leaf[adj];
        }
        dbg(s+1, adj+1, to_leaf[s], first, second);
    }
    max_len[s] = first + second + 2;
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

    if (n == 1) { cout << 0 << '\n'; return 0; }
    if (n == 2) { cout << 1 << '\n'; return 0; }
    // Rooteo de cualquier con mas de 1 hijo (cualquiera q no sea hoja)
    int root;
    forn(i, n){
        if (G[i].size() > 1){
            root = i;
            break;
        }
    }
    dfs(root, -1);
    int d = *max_element(max_len, max_len + n);
    cout << d << '\n';
 
    return 0;
}
