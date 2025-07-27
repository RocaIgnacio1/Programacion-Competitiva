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



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, s; 
    cin >> n >> s;
    vector<int> a(n);
    vector<int> dp(s, 0);
    a.resize(n);
    forn(i, n) cin >> a[i];
    // sort(a.begin(), a.end());

    dp[0] = 1;
    forn(i, n){
        for(int w = 0; w <= s; w++){
            if (w - a[i] >= 0){
                dp[w] += dp[w - a[i]];
                dp[w] %= MOD;
            }
        }
    }

    cout << dp[s] << endl;
  
    return 0;
}
