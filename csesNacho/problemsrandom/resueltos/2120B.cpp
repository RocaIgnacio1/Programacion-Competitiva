#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

bool check(ll a, ll b, ll c,ll d, ll x, ll y ){
    double k = (double) 0;
    k = (double)(x-a) / double(c);
    if(k*d==(y-b)) return true;
    else return false;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        ll s;
        cin >> n >> s;
        ll ans=0;
        forn(i,n){
            ll a,b,c,d;
            cin >> c >> d >> a >> b;
            // esquinas (0,0) (0,s) (s,0) (s,s)
            if(check(a,b,c,d,0,0) || check(a,b,c,d,0,s) || check(a,b,c,d,s,0) || check(a,b,c,d,s,s)){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}