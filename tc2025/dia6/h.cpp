#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define ll long long

using namespace std;

int n, m;
array<vector<int>, 1000001> sons;
array<set<int>, 1000001> caminos;
vector<int> camino;

void recorrer(int i, int con){
    if(camino[i] != -1) return;
    caminos[con].insert(i);
    camino[i] = con;
    forn(j, sons[i].size()){
        recorrer(sons[i][j], con);
    }
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    
    cin >> n >> m;
    vector<pair<int, int>> v;

    forn(i, n){
        int k;
        cin >> k;
        v.push_back({k, i});
        camino.pb(-1);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    forn(i, m){
        int y, j;
        cin >> y >> j;
        sons[y-1].push_back(j-1);
        sons[j-1].push_back(y-1);
    }
    int con = 0;
    forn(i, n){
        if(camino[i] == -1){
            recorrer(i, con);
            con ++;
        }
    }

    vector<int> ret(n);
    forn(i, n){
        //cout << v[i].first << " " << camino[v[i].second] << endl;
        auto it = caminos[camino[v[i].second]].begin();
        ret[*it] = v[i].first;
        caminos[camino[v[i].second]].erase(*it);
    }

    forn(i, n){
        cout << ret[i] << " " << " ";
    }





    return 0;
}