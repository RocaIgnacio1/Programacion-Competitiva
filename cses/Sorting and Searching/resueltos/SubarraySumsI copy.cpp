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
    // igual -> aumento i y j
    // menor -> j++
    // mayor -> i++
    
    ll ans=0, sum=0, i=0, j=0;
    while(j<n){
        while(j<n && sum<x){
            sum+=a[j];
            j++;
        }

        while(i<=j && sum>x){
            sum-=a[i];
            i++;
        }

        if(sum==x){
            ans++;
            sum-=a[i];
            i++;
        }
    }
    cout << ans << endl;

    return 0;
}