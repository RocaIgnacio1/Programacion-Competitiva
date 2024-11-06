#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

struct triple{
    ll uno,dos,tres;
};
bool sortby(const triple &a, const triple &b){
    if(a.uno==a.dos) return (a.dos<a.dos);
    return (a.uno > b.uno);
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m = 0, n;
    ll ans = 0;
    cin >> n;
    ll p[n][n];
    forn(i,n){
        forn(j,n){
            cin >> p[i][j];
            m = max(m,p[i][j]);
        }
    }
    vector<triple> maxs;
    ll hasta=-1;
    forn(i,n){
        hasta++;
        forn(j,hasta){
            triple a;
            a.uno = p[i][j];
            a.dos = i;
            a.tres = j;
            maxs.pb(a);
        }
    }
    
    sort(maxs.begin(),maxs.end(), sortby);

    map<ll,ll> eliminados;
    vector<pair<ll,ll>> orden;

    forn(i,maxs.size()){
        ll val1 = maxs[i].dos;
        ll val2 = maxs[i].tres;
        auto it1 = eliminados.find(val1);
        auto it2 = eliminados.find(val2);
        if(it1 == eliminados.end() && it2 == eliminados.end()){
            orden.pb(make_pair(maxs[i].dos, maxs[i].tres));
            eliminados[max(val1,val2)] = 1;
        }
    }

    forn(i, orden.size()){
        //cout << orden[i].first+1 << " " << orden[i].second+1 << endl;
        ll minim = min(orden[i].first,orden[i].second);
        ll maxm = max(orden[i].first,orden[i].second);
        //cout << p[orden[i].first][orden[i].second] << endl;
        ans += p[orden[i].first][orden[i].second];       
        forn(i,n){
            p[minim][i] = max(p[minim][i], p[maxm][i]);
        }
        forn(i,n){
            p[i][minim] = p[minim][i];
        }
        
    }
    
    cout << ans << endl;
    forn(i, orden.size()){
        cout << orden[i].first+1 << " " << orden[i].second+1 << endl;
    }
    

}
