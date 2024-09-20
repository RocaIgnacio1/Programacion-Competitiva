#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif
const int tablero = 105;
int dp[tablero][tablero];

int mex(vector<int> &v) {
    sort(v.begin(), v.end());
    int mexVal = 0;
    for(int x : v) {
        if(x == mexVal) mexVal++;
    }
    return mexVal;
}

int cargardp(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];

    vector<int> p;
    for (int k = 1; k < i; k++) {
        if(j==i-k)continue;
        p.push_back(cargardp(i - k, j));
    }
   
    for (int k = 1; k < j; k++) {
        if(i==j-k)continue;
        p.push_back(cargardp(i, j - k));
    }
    for (int k = 1; k < min(i, j); k++)p.pb(cargardp(i - k, j - k));

    return dp[i][j] = mex(p);
}

int main() {
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    
    for (int i = 1; i < tablero; i++) {
        for (int j = 1; j < tablero; j++) {
            if (dp[i][j] == -1) cargardp(i, j);
        }
    }
    /*
    for (int i = 0; i < tablero; i++) {
        for (int j = 0; j < tablero; j++) {
            cout << dp[i][j] << " ";
        }   
        cout << endl;
    }
    */
    
    int n;
    cin >> n;
    int res = 0;
    forn(i, n) {
        int a, b;
        cin >> a >> b;
        if(a==b){
            cout << "Y" << endl;
            return 0;
        }
        res ^= dp[a][b];
    }
    if (res != 0) cout << "Y" << endl;
    else cout << "N" << endl;
    
    return 0;
}
