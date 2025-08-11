#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000
//const ll mod = 1000000007;

ll solve(ll a, ll b, ll mod){
    if(b==0)return 1;
    if(b==1)return a%mod;

    ll ans = solve(a,b/2,mod) % mod;

    if(b%2==0){
        return (ans*ans)%mod;
    }else{
        return (((ans*ans)%mod) * a )%mod;
    }

}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>> n;
    forn(j,n){
        ll a, b, c;
        cin>>a>>b>>c;
        cout<<solve(a,solve(b,c,1000000006),1000000007)<<endl;
    }    

    return 0;
}

