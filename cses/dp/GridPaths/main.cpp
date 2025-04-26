#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

const int INF = INT_MAX;
const int MAXN = 1000;
const int M = 1e9 + 7;

int dp[MAXN][MAXN];
int n;

int solve(int i, int j) {
    if (i < 0 || i >= n) return 0;
    if (j < 0 || j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (solve(i-1, j)%M + solve(i, j-1)%M)%M;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    forn(i, n){
        forn(j, n){
            char c;
            cin >> c;
            dp[i][j] = (c == '.' ? -1 : 0);
        }
    }

    if (dp[0][0] == 0) {
        cout << 0 << endl;
        return 0;
    }

    dp[0][0] = 1;

    cout << solve(n-1, n-1) << '\n';
}
