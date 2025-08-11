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
    
    int tt=1;
    while(tt--){
        int n; cin >> n;
        vector<int> a(n);
        forn(i,n)cin >> a[i];
        
        int ans=0;
        vector<int> flechas(1000010);
        forn(i,1000010)flechas[i]=0;
        forn(i,n){
            if(flechas[a[i]]>0){
                flechas[a[i]-1]++;
                flechas[a[i]]--;
            }else{
                ans++;
                flechas[a[i]-1]++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}