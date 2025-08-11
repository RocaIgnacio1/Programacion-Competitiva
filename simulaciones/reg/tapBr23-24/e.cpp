#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

int sumdg(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int dp[1000100];
int solve(int i){
    if (i > 99999) return dp[i] = 0;
    return dp[i] = 1 + solve(i + sumdg(i));
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> f(n+1);
    forn(i, n) cin >> f[i];
    sort(f.begin(), f.end());
    dp[9] = 1;
    dp[18] = 1;
    dp[27] = 1;
    dp[36] = 1;
    dp[45] = 1;
    dp[54] = 1;
    dp[63] = 1;
    dp[72] = 1;
    dp[81] = 1;
    for(int i = 90; i < 1000000; i+=9){
        dp[i] = 1 + dp[i-sumdg(i)];
    }
    solve(0);

    vector<int> vir(n);
    forn(i, n) vir[i] = sumdg(f[i]);
    vector<ll> range = {1};
    ll acum = 0;
    forn(i, n){
        if(vir[i+1] != 0)acum++;
        forn(j, 10){
            if(dp[f[i]])
        }
        range.push_back(dp[f[i]]);
    }
  
    return 0;
}