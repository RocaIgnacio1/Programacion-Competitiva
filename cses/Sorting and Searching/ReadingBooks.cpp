#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
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

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<ll> t(n);
    forn(i,n){
        cin >> t[i];
    }
    sort(t.begin(),t.end());
    ll sum=0;
    forn(i,n-1){
        sum+=t[i];
    }

    cout << sum + max(ll(0),t[n-1]-sum) + t[n-1] << endl;
    
    return 0;
}