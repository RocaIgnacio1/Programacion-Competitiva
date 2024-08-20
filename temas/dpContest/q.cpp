#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back
#define mod 1000000007
const int MAXN = 1000;
int n;
vector<vector<ll>> dp(MAXN, vector<ll>(MAXN, -1)); 
int h[MAXN];
ll a[MAXN];

ll solve(int i, int anterior) {    
    if (i == n) return 0;
    if (dp[i][anterior]!=-1) return dp[i][anterior];

    ll tomar = 0;
    if (h[i] > anterior) {
        tomar = solve(i + 1, h[i]) + a[i];
    }
    ll noTomar = solve(i + 1, anterior);

    dp[i][anterior] = max(tomar, noTomar);
    return dp[i][anterior];
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    forn(i,n){
        cin >> h[i];
    }
    forn(i,n){
        cin >> a[i];
    }
      
    cout << solve(0,0) << endl;
    cout << dp[3][1] << " " << dp[3][3] << " " << dp[2][2] << endl;
}