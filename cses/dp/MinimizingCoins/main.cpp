#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

const int MAXN = 100;
const int MAXX = 1e6+1;

int N;
int coins[MAXN];
vector<int> dp;

int solve(int x) {
    if (x == 0) return 0;
    if (x < 0) return MAXX;
    if (dp[x] != -1) return dp[x];

    int m = MAXX;
    forn(i, N) { 
        m = min(solve(x - coins[i]), m);
    }
    return dp[x] = m+1;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x;
    cin >> N >> x;

    dp.assign(x+1, -1);

    forn(i, N){
        cin >> coins[i];
    }

    int ans = solve(x);
    if (ans >= MAXX) {
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
}
