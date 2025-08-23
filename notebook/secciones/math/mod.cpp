typedef long long ll;
const int MAXN = 1e7, M = 1e9+7;

ll expmod(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = ans*b %M;
        b = b*b %M; e >>= 1;
    }
    return ans;
}

ll invmod(ll a){ return expmod(a, M-2); }

// Inversos modulares
int INV[MAXN];
INV[1] = 1;
for(ll a = 2; a < MAXN; a++) INV[a] = M - (ll)(M/a)*INV[M%a]%M;

// Factoriales
ll F[MAXN];
F[0] = 1;
for(ll i = 1; i < MAXN; i++) F[i] = F[i-1]*i %M;

// Factorial inverso
int FI[MAXN]
FI[0] = 1; 
for(int i = 1; i < MAXN; i++) FI[i] = FI[i-1]*INV[i] %M

// Combinaciones
ll Comb(ll n, ll k){
    if(n < k) return 0;
    return F[n]*FI[k] %M *FI[n-k] %M;
}
