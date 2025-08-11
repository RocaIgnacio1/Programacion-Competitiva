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
const ll MAXN = 10000000000;
vector<vector<int>> adj(100009);
bool visitado[100009];
vector<int> mx(100009), valores;
map<int, vector<int>> act;

void solve(int i, int ultimo){
    if(visitado[i]) return;
    visitado[i] = true;
    vector<int> p;
    //cout << i << " " << valores[i] << endl; 
    auto pos = act.lower_bound(valores[i]);
    if (pos != act.begin()){
        pos--;
        p = pos->second;
    }
    //cout << p << endl;
    //cout << i << " " << p << endl;
    //cout << p.size() << endl;
    int number = (!p.size())?0:p.back();
    mx[i] = max(ultimo, mx[number]+1);
    act[valores[i]].push_back(mx[i]);
    forn(j, adj[i].size()){
        solve(adj[i][j], mx[i]);
    }
    act[valores[i]].pop_back();
    if(act[valores[i]].empty()) act.erase(valores[i]);
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    forn(i, n-1){
        int k;
        cin >> k;
        adj[k].push_back(i+2);
        adj[i+2].push_back(k);
    }
    valores.push_back(0);
    forn(i, n){
        int k;
        cin >> k;
        valores.push_back(k);
    }
    mx[0] = 0;
    solve(1, 0);
    forn(i, n-1){
        cout << mx[i+2] << ' ';
    }
    cout << endl;
}