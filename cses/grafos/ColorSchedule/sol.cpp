#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;

const int MAXN = 1e5;

/* Solucion: 
 *  Topological Sort
 * */

vector<int> state;
vector<vector<int>> G;
vector<int> order;

bool dfs(int nodo){
    if(state[nodo] == 2) return false;
    state[nodo] = 1;

    bool cicle = false;
    for(auto it : G[nodo]){
        if(state[it] == 0){ 
            cicle = dfs(it);
        }else if(state[it] == 1){
            return true;
        }
    }
    state[nodo] = 2;
    order.push_back(nodo);
    return cicle;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    state.assign(n+1, 0);
    G.assign(n+1, vector<int>());

    forn(i, m){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
    }

    bool cicle = false;
    forn(i, n){
        if (state[i] == 0){
            cicle = dfs(i);
        }
        if (cicle) break;
    }

    if (cicle){
        cout << "IMPOSSIBLE\n";
    }else{
        reverse(order.begin(), order.end());
        for(int i : order){
            cout << i+1 << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}
