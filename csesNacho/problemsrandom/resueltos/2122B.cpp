#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

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
        cin >> n;
        ll ans=0;
        forn(i,n){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            if(a>c)ans+=a-c;
            if(a>c)a=c;
            if(b>d)ans+=a;
            if(b>d)ans+=b-d;
        }
        cout << ans << endl;
    }

    return 0;
}