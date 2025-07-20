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

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        array<vector<int>, 200010> v;
        vector<int> ran(200010, -1), dp(200010, 0);
        vector<bool> notome(200010, true);
        forn(i, n){
            int k;
            cin >> k;
            v[k].push_back(i);
        }

        forn(i, n+1){
            forr(j, 1, v[i].size()){
                ran[v[i][j-1]] = v[i][j];
            }
        }

        dforn(i, n-1){
            if(ran[i] == -1){
                dp[i] = dp[i+1];
                continue;
            } 
            //cout << ran[i]-i + dp[ran[i]] + notome[ran[i]] << " " << dp[i+1] << endl;
            if(ran[i]-i + dp[ran[i]] + notome[ran[i]] <= dp[i+1]){
                dp[i] = dp[i+1];
                notome[i] = true;
            }else{
                dp[i] = ran[i]-i + dp[ran[i]] + notome[ran[i]];
                notome[i] = false;
            }
        }
        
        cout << dp[0] << endl;
    }
    return 0;
}