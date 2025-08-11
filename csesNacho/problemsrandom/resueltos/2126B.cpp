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
        vector<int> a(n);
        forn(i,n)cin>>a[i];
        int ans=0, suma=0;
        forn(i,n){
            if(a[i]==0){
                suma++;
            }else{
                suma=0;
            }
            if(suma==k){
                suma=0;
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}