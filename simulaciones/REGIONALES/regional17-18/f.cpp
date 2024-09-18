#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define MAXN 100000
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
struct P {
    int b, f, d;
};

bool ord(const P &a, const P &b){
    return sqrt(a.b*a.b + a.f*a.f) > sqrt(b.b*b.b + b.f*b.f);
}

vector<P> personas;

int dp[MAXN];
ll solve(int i){
    if (i >= n-1) return 0;
    if (dp[i] != -1) return dp[i];

    cout << dp[i] << endl;
    return dp[i] = solve(i+1) + personas[i].d;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    memset(dp, -1, n+1);
    forn(i, n){
        int b, f, d;
        cin >> b >> f >> d;
        personas.push_back(P{b, f, d});
    }

    sort(personas.begin(), personas.end(), ord);
    for(auto p : personas){
        cout << p.b << " " << p.f << " " << p.d << endl;
    }

    ll ans = solve(0);
    cout << ans << endl;

    return 0;
}