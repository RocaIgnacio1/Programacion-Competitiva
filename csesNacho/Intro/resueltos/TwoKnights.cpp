#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000




int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n; cin >> n;

    vector<ll> res;
    res.push_back(0);
    res.push_back(6);
    res.push_back(28);
    res.push_back(96);

    ll pot=1;
    for(int i=1; i<=4;i++){
        pot *= i;
    }
    
    for(ll i=5; i<=n; i++){
        ll esq = 4;//2
        ll bordes = 8;//3
        ll per = (i-4)*4;//4
        ll esq_int = 4;//4
        ll per_int = (i-4)*4;//6
        ll resto = ((i*i) - (esq+bordes+per+esq_int+per_int));
       
        res.push_back((i*i*(i*i-1) - (2*esq+3*bordes+4*per+4*esq_int+6*per_int+8*resto))/2);

    }
    
    forn(i,n)cout <<res[i]<<endl;
    return 0;
}