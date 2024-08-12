#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

vector<int> v[100002];
bool revisado[100002];

int dfs(int nodo){
    int res = 0;
    if(revisado[nodo]) return 0;
    revisado[nodo] = true;
    for(auto it : v[nodo]) if(!revisado[it]) res = max(res, 1 + dfs(it));
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, m, D;
    cin >> n >> m >> D;
    forn(i, m){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    forn(i, n) revisado[i] = false;
    if(dfs(1) >= D){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


}