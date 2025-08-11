#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
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
    cin>>tt;
    while(tt--){
        int n,k;
        cin >> n >> k;
        
        vector<ll> minimos,a(n),b(n);
        ll ans=0;
        forn(i,n){
            cin >> a[i];
        }
        forn(i,n){
            cin >> b[i];
        }
        forn(i,n){
            minimos.push_back(min(a[i],b[i]));
            ans+=max(a[i],b[i]);
        }

        sort(minimos.begin(),minimos.end());
        reverse(minimos.begin(),minimos.end());
        forn(i,k-1){
            ans+=minimos[i];
        }
        cout << ans+1 << endl;
    }

    return 0;
}