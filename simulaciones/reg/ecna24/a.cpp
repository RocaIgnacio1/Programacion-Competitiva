#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> a;
    ll n;
    cin >> n;

    forn(i,n){
        ll val;
        cin >> val;
        a.pb(val);
    }
  
    vector<ll> may(n+1);
    may[0]=a[0];
    forn(i,n){
        if(i==0)continue;
        may[i] = max(may[i-1],a[i]);
    }

    vector<ll> men(n+1);
    men[n-1]=a[n-1];
    for(ll i=n-1 ; i>=0 ; i--){
        if(i==n-1)continue;
        men[i] = min(men[i+1],a[i]);
    }

    vector<ll> res;

    forn(i,n){
        if(may[i]<=a[i] && men[i]>=a[i]){
            res.pb(a[i]);
        }        
    }

    int c = res.size();
   
    if(c>100)cout << 100 << " ";
    else cout << c << " ";
    forn(i,min(100,c) ){
        cout << res[i] << " ";
    }
    return 0;
}
