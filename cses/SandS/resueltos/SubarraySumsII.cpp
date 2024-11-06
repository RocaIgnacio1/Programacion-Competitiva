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
    ll x;
    vector<ll> a;
    cin >> n >> x;
    forn(i,n){
        ll num;
        cin >> num;
        a.pb(num);
    }

    ll sum=0, ans=0;
    vector<ll> prefix;
    map<ll,ll> vals;
    vals[0]++;
    forn(i,n){
        sum+= a[i];
        if(vals.count(sum-x)>0){
            ans+=vals[sum-x];
        }
        prefix.pb(sum);
        vals[sum]++;
    }
    cout << ans << endl;
    return 0;
}