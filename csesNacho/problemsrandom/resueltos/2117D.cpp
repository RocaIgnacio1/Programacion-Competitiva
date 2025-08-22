#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
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
        vector<ll> a(n);
        forn(i,n)cin >> a[i];

        ll num = (n-1)-(2*n);
        ll der = a[1]-(2*a[0]);

        if(der%num!=0){
            cout << "NO" << endl;
            continue;
        }
        ll x = der/num;
        ll y = a[0]-n*x;
        
        if(x<0||y<0){
            cout << "NO" << endl;
            continue;
        }
        bool ans=true;
        forn(i,n){
            ll resta = (i+1)*y + (n-(i+1)+1)*x;
            if(a[i]-resta!=0){
                ans=false;
                break;
            }
        }

        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}