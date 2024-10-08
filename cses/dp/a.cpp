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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    ll dp[100001];
    if(n == 1) {cout << 1 << endl; return 0;}
    if(n == 2) {cout << 2 << endl; return 0;}
    if(n == 3) {cout << 4 << endl; return 0;}
    if(n == 4) {cout << 8 << endl; return 0;}
    if(n == 5) {cout << 16 << endl; return 0;}
    if(n == 6) {cout << 32 << endl; return 0;}
    ll acum = 32;
    dp[6] = 32;
    for(int i = 7; i <= n; i++){
        dp[i] = dp[i-1] + acum;
        dp[i-1]--;
        acum += dp[i-1];
    }
    cout << dp[n] << endl;
}