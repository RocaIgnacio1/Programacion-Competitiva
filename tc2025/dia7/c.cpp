#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;

 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    
    int n;
    cin >> n;

    vector<pair<ll,ll>> puntos;

    forn(i,n){
        ll x,y;
        cin >> x >> y;
        puntos.push_back(make_pair(x,y));
    }
    cout << "YES" << endl;
    sort(puntos.begin(),puntos.end());
    reverse(puntos.begin(),puntos.end());
    forn(i,n-1){
        cout << puntos[i].first << " " << puntos[i].second << endl;
    }
    return 0;
}
