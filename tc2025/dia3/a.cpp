#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
 
#define ll long long
 
#ifdef EBUG
// local
#else
// judge
#endif
 
using namespace std;

int v[100010] = {0};
int dp[100010];

int sol(int n){
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    if(v[n] == 0) return dp[n] = sol(n - 1);
    return dp[n] = sol(n - v[n] - 1) + 1;
}
 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n; cin >> n;
    
    forn(i,n){
        int a,b;
        cin >> a >> b;
        v[a]=b;
    }
   
    memset(dp,-1, sizeof(dp));
    int a=0;
    forn(i, 100010){
        a = max(a,sol(i));
    }
    cout << n-a << endl;
    
    return 0;
}