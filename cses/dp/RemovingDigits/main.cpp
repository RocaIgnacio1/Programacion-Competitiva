#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;

using namespace std;

const int MOD = 1e9+7;
const int MAXC = 1e6+1;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; 
    cin >> n;
    vector<int> dp(n+1, 1e9);
    
    dp[0] = 0;
    for(int w = 1; w <= n; w++){
        for(int i = w; i > 0; i /= 10){
            int d = i % 10;
            if (w - d < 0) continue;
            dp[w] = min(dp[w], dp[w - d] + 1);
        }
    }
    cout << dp[n] << endl;
  
    return 0;
}
