#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define modsum(a, b) ((a%M + b%M)%M)

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 11;
const int MAXM = 1001;
const int M = 1e9+7;

ll dp[MAXN][MAXM];

vector<ii> tiles = {{1, 2}, {2, 1}};

ll solve(int a, int b) {
    if (a <= 0 || b <= 0) return 0; 
    if (dp[a][b] != -1) return dp[a][b];

    ll ans = 0;
    forn(i, a){
        forn(j, b){
            for(auto [w, h] : tiles) {
                ans = modsum(ans, modsum(solve(i, b), solve(a-i-w, b)));
                ans = modsum(ans, modsum(solve(w, j), solve(w, b-j-h)));
                ans = modsum(ans, modsum(solve(i, h), solve(a-i-w, h)));
                ans = modsum(ans, modsum(solve(a, j), solve(a, b-j-h)));
            }
        }
    }
    return dp[a][b] = ans;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));

    dp[1][2] = 1;
    dp[2][1] = 1;
    dp[1][1] = 0;

    cout << solve(a, b) << '\n';
}
