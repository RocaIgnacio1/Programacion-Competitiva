#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000
const ll mod = 1000000007;

ll dp[1000100];
ll x, n;
vector<ll> a;

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>x;
    forn(i,n){
        ll val; cin>>val;
        a.push_back(val);
    }
    memset(dp,0,sizeof(dp));
    
    dp[0]=1;

    for(ll s=0; s<=x; s++){
        if(dp[s]==0)continue;
        for(ll coin: a){
            if(s+coin<=x){
                dp[s+coin] = (dp[s+coin]+dp[s])%mod;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}