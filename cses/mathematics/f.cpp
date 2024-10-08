#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll inf = 1e18+100;
const ll mod = 1e9+7;
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
 
#ifdef EBUG
#else
#endif

vector<ll> v;
void posibles(ll n){
    for(ll i = 1; i*i <= n; i++){
        v.push_back(i);
        if(i!=(n/i)){
            v.push_back(n/i);
        }
    }
}
ll modInverse(ll a, ll m) {
    ll res = 1;
    ll power = m - 2; // Inverso modular bajo número primo
    while (power > 0) {
        if (power % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        power /= 2;
    }
    return res;
}

ll MOD = 1e9+7;
ll inv2 = modInverse(2, MOD);
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    posibles(n);
    ll res = 0;
    ll con = 1;
    sort(v.begin(), v.end());
    for(auto i: v){
        //i %= MOD;
        //n %= MOD;
        ll b = n/i;
        ll n = i;
        ll m = con;
        ll x = (n-m+1)%MOD;
        ll y = (n+ m)%MOD;
        ll p = ((((x)*(y)))%MOD)*inv2;
        //cout << n << " " << m << " " << x%MOD << " " << y%MOD << " " << b << " " << p << endl;
        res += (b % MOD * p % MOD)%MOD;
        res %= MOD;
        con = i+1;
    }
    cout << res << '\n';
    return 0;
}