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
int n;
ll dp[1000100];

ll solve(int m){
    if(m<0)return 0;
    if(m==0)return 1;
    if(dp[m]!=-1)return dp[m];
    ll a=0;
    forn(i,6){
        a = (a+(solve(m-(i+1))%mod))%mod;
    }
    return dp[m] = a;
}

int main(){
    #ifdef EBUG
        //freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    forn(i,1000100)dp[i]=-1;
    cout << solve(n) << endl;
}