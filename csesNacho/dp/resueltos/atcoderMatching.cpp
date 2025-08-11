#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll inf = 1e18+100;
const ll mod = 1000000007;

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
const ll MAXN = 25;
int n;
int a[MAXN][MAXN];
ll dp[1 << MAXN];

ll solve(int fila, int parejas, int mascara){
    if(parejas==n) return 1;
    if(fila==n) return 0;
    if(dp[mascara]!=-1)return dp[mascara];
    ll res=0;
    forn(i,n){
        if(mascara & (1<<i))continue;
        if(a[fila][i]==0)continue;

        res = ((res + solve(fila+1,parejas+1, mascara | 1 << i)%mod)%mod);
    }
    return dp[mascara] = res;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    forn(i,n){
        forn(j,n){
            cin >> a[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0,0,0) << endl;
    return 0;
}