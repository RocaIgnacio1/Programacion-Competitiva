#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back
#define MAXN 410
int n;
ll dp[MAXN][MAXN];
vector<ll> A;
ll suma(int a, int b){
    if(a==0) return A[b];
    
    return (A[b]-A[a-1]);
}
ll sol(int a, int b){
    if(a==b) return 0;
    if(a>b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    ll ans=1e18;
    for(int k=a;k<b;k++){
        ans = min(ans, sol(a,k) + sol(k+1,b) + suma(a,b));
    }

    return dp[a][b]=ans; 
}

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> n;
    forn(i,n){
        ll valor;
        cin >> valor;
        A.pb(valor);
    }
    for(ll i=1;i<n;i++)
    {
        A[i] += A[i-1];
    }
    memset(dp,-1, sizeof(dp));
    
    cout << sol(0,n-1) << endl;
    
}