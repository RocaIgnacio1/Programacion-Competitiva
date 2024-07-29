#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fori(i, n) for(ll i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    //freopen("input.txt","r",stdin);
    ll t;
    cin >> t;
    forn(i,t){
        ll n; 
        cin >> n;
        vector<ll> b;
        forn(j,n-1){
            ll valor;
            cin >> valor;
            b.pb(valor);
        }
        vector<ll> a(n);
        a[0]=b[0];

        //cout << "hola" <<endl;
        for(ll j=1;j<n-1;j++){
            a[j] = b[j-1] | b[j];
        }
        a[n-1] = b[n-2];
        bool ban=true;
        for (ll i = 1; i < n - 1; ++i) {
            if ((a[i] & a[i + 1]) != b[i]) {
                cout << -1 << endl;
                ban=false;
                break;
            }
        }
        if(ban){
            forn(j,n){
            cout << a[j] << " " ;
            }
        cout << endl;
        }
        
    }
    
    
    return 0;
}
