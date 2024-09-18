#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    deque<ll> f(n);
    deque<ll> c(n);
    forn(i,n)cin>>f[i];
    forn(i,n)cin>>c[i];

    sort(f.begin(),f.end());
    sort(c.begin(),c.end());
    /*
    forn(i,n){
        cout << f[i] << " ";
    }
    cout << endl;
    forn(i,n){
        cout << c[i] << " ";
    }
    */
    ll maxi = INF;
    ll mini = -INF;
    ll ans = 0;
    forn(i,n){
        ll bf = f.back();
        ll ff = f.front();
        ll bc = c.back();
        ll fc = c.front();
        
        maxi = max(maxi, bf*bc);
        maxi = max(maxi, bf*fc);
        maxi = max(maxi, ff*bc);
        maxi = max(maxi, ff*fc);
        if(bf*bc>bf*bc)
        ans+=maxi;
        cout << ans << endl;
    }
    

    return 0;
}