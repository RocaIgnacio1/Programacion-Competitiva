#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) for(auto i : v) cout << i << " ";

int main(){
    freopen("input.txt", "r", stdin);
    int n,m,q;
    cin >> n >> m >> q;
    map<int, int> loc;
    for(int i=1; i<=m;i++)loc[i]=0;
    
    int maxl = 0;
    forn(i, n){
        int valor;  
        cin >> valor;
        loc[valor]++;
        int a=loc[valor];
        maxl = max(maxl, a);
    }
    
    ll igualados=0;
    for(int i=1; i<=m;i++){
        igualados += maxl - loc[i];
    }
    
    
    forn(i,q){
        ll consulta;
        cin >> consulta;
        if(consulta>igualados+n){
            int ans;
            ans = consulta % m;
          
            if(ans==0){
                cout << m << endl;
            }else{
                cout << ans << endl;
            }
        }else{
            
        }
    }
    
    return 0;
}