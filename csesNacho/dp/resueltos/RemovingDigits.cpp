#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000
const ll mod = 1000000007;

int n, dp[1000100];

int solve(int num) {
    if(num<=0)return 0;
    if(dp[num]!=-1)return dp[num];

    string s = to_string(num);
    int ans = INT_MAX;
    forn(i,s.size()){
        int digito = s[i]-'0';
        if(digito==0)continue;
        ans = min(ans, 1+solve(num-digito));
    }

    return dp[num]=ans;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    forn(i,1000100)dp[i]=-1;
    cout << solve(n) << endl;

    return 0;
}