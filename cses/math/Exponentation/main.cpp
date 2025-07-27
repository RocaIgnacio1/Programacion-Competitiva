#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll p = modpow(x, n/2);
    p = (p*p)%MOD;
    if (n%2 != 0) p = (p*x)%MOD;
    return p;
}

int main(){
    HOLA
    int t; cin >> t;

    while(t--){
        ll a, b; cin >> a >> b;
        cout << modpow(a, b) << endl;
    }
 
    return 0;
}
