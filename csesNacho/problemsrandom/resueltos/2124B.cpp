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
        vector<ll> a(n);
        forn(i,n){
            cin >> a[i];
        }
        if(n==2){
            cout << a[0] + min(a[0],a[1]) << endl;
            continue;
        }
        
        ll f1 = a[0];
        // f1 no hacer nada
        ll s=a[0];
        forr(i,1,n){
            s=min(s,a[i]);
            f1+=s;
        }
        // f2 swap 1 y 2
        ll f2 = a[0] + a[1];
        // f3 swap 2 y 3
        ll f3= a[0] + min(a[0],a[1]+a[2]);
        cout << min(f1,min(f2,f3)) << endl;

    }

    return 0;
}