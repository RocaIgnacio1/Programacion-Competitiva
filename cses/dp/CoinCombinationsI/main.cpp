#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;

using namespace std;

const int MOD = 1e9+7;
const int MAXC = 1e6+1;
const int MAXN = 110;

int n;
vector<int> a;
vector<int> dp(MAXC, -1);

int solve(int s){
    if (s < 0) return 0;
    if (dp[s] != -1) return dp[s];
    int count = 0;
    forn(i, n){
        count = (count + solve(s-a[i])) % MOD;
    }
    return dp[s] = count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int s; 
    cin >> n >> s;
    a.resize(n);
    forn(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    dp[0] = 1;
    cout << solve(s) << endl;
  
    return 0;
}
