#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

const int MAXN = 501;

int dp[MAXN][MAXN];

int solve(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    int m = INT_MAX;
    for(int i = 1; i < a; i++){
        m = min(m, solve(a-i, b) + solve(i, b) + 1);
    }
    for(int j = 1; j < b; j++){
        m = min(m, solve(a, b-j) + solve(a, j) + 1);
    }
    return dp[a][b] = m;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << solve(a, b) << '\n';
}
