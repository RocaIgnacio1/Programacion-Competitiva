#include <bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define forn(i, n) forr(i,0,n)
#define dforn(i, n) for(int i= (n) -1; i >= 0; i--)

typedef long long ll;
const int MAXN = 1e7;
const int M = 1e9+7;

ll F[MAXN], INV[MAXN], FI[MAXN];

using namespace std;

ll comb(ll n, ll k){
    if(n < k) return 0;
    return F[n]*FI[k] %M *FI[n-k] %M;
}

ll expmod(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = ans*b %M;
        b = b*b %M; e >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
    int N, m, K;

    cin >> N >> m >> K;

    F[0] = 1; forr(i, 1, MAXN) F[i] = F[i-1]*i % M; 
    INV[1] = 1; forr(i, 2, MAXN) INV[i] = M - (ll)(M/i)*INV[M%i]%M;
    FI[0] = 1; forr(i, 1, MAXN) FI[i] = FI[i-1]*INV[i] %M;

    ll ans = comb(m, K) % M * comb(N, K)%M * F[K]%M;
    cout << ans << '\n';

    return 0; 
}
