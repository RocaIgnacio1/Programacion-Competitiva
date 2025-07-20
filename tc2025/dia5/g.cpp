#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;

using namespace std;
typedef long long ll;
const int MAXN = 2*1e5+10;

int n, m;
vector<int> child[MAXN]; // child, tiene gato
vector<int> gato(MAXN);
vector<bool> v(MAXN, false);

int dfs(int i, int consec){
    int ans = 0;
    cerr << i+1 << " " << consec << ' ' << m << endl;
    v[i] = true;
    if (consec > m) return 0;
    if (child[i].size() == 0) return 1;
    for(auto c : child[i]){
        if (v[c]) continue;
        if (gato[c]){
            ans += dfs(c, consec+1);
        }else{
            ans += dfs(c, 0);
        }
    }
    return ans;
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    forn(i, n) cin >> gato[i];
    forn(i, n-1){
        int a, b;
        cin >> a >> b; a--; b--;
        //cout << a << ' ' << b << endl;
        child[a].push_back(b);
        child[b].push_back(a);
    }

    forn(i, n){
        cout << i+1 << ": ";
        for(auto adj : child[i]){
            cout << adj+1 << ' ';
        }
        cout << endl;
    }

    cout << dfs(0, gato[0]) << endl;
    
    return 0;
}