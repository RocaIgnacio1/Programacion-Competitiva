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
int n,x;
vector<int> coins;
//1000100
int dp[1000100];
int solve(int monto){
    if(monto==x) return 0;
    if(monto>x)return 1000000000;
    if(dp[monto]!=-1)return dp[monto];
    int a=1000000000;
    forn(i,n){
        a = min(a,solve(monto+coins[i])+1);
    }
    return dp[monto]=a;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> x;
    forn(i,n){
        int a;
        cin >> a;
        coins.push_back(a);
    }
    
    forn(j,1000100){
        dp[j]=-1;
    }
    int a = solve(0);
    if(a>=1000000000)cout << -1 << endl;
    else cout << a << endl;
}