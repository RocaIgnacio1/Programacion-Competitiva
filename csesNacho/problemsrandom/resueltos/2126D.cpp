#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

bool comp(const tuple<ll,ll,ll> &a, const tuple<ll,ll,ll> &b){
    if(get<0>(a)==get<0>(b)) return get<1>(a)<get<1>(b);
    else return get<0>(a)<get<0>(b);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        ll k;
        cin >> n >> k;

        vector<tuple<ll,ll,ll>> a(n);
        forn(i,n){
            cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
        }
        sort(a.begin(),a.end(),comp);
        ll ans = k;

        forn(i,n){
            if(ans>=get<0>(a[i]) && ans<=get<1>(a[i])){
                ans = max(ans, get<2>(a[i]));
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}