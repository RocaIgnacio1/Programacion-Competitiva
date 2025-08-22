#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define sz(v) (int(v.size()))
#define pb push_back


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   int n;
    cin >> n;
    vector<ll> mn(4, LLONG_MAX), mx(4, LLONG_MIN);

    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;

        ll vals[4] = {x+y, x-y, -x+y, -x-y};

        for (int k = 0; k < 4; k++) {
            mn[k] = min(mn[k], vals[k]);
            mx[k] = max(mx[k], vals[k]);
        }

        ll ans = 0;
        for (int k = 0; k < 4; k++) {
            ans = max(ans, mx[k] - mn[k]);
        }
        cout << ans << endl;
    }

    return 0;
}