#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define MAXN 1000000008
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif

int n;
map<int, set<int>> B;
map<int, set<int>> F;
map<int, map<int, ll>> D;

map<int, map<int, ll>> dp;
ll solve(int i, int j){
    if (dp[i][j] != -1) return dp[i][j];
    ll ans = D[i][j];
    auto ub = upper_bound(B[i].begin(), B[i].end(), j);
    if (ub != B[i].end()){
        ans = max(ans, solve(i, *ub));
    }
    auto a = next(B.find(i));
    if (a != B.end()){
        ub = upper_bound(a->second.begin(), a->second.end(), j);
        if (ub != a->second.end()){
            ans = max(ans, D[i][j] + solve(a->first, *ub));
        }
    }

    ub = upper_bound(F[j].begin(), F[j].end(), i);
    if (ub != F[j].end()){
        ans = max(ans, solve(*ub, j));
    }
    auto a2 = next(F.find(j));
    if (a2 != F.end()){
        ub = upper_bound(a2->second.begin(), a2->second.end(), i);
        if (ub != a2->second.end()){
            ans = max(ans, D[i][j] + solve(*ub, a2->first));   
        }
    }
    return dp[i][j] = ans;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    D[0][0] = 0;
    dp[0][0] = -1;

    cin >> n;
    B[0].insert(0);
    F[0].insert(0);
    forn(i, n){
        ll b, f, d;
        cin >> b >> f >> d;
        B[b].insert(f);
        F[f].insert(b);
        D[b][f] += d;
        dp[b][f] = -1;
    }

    cout << solve(0, 0) << '\n';

    return 0;
}