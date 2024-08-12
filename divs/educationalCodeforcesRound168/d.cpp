#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    
    forn(w,t){
        int n;
        cin >> n;
        
        vector<ll> padres;
        vector<ll> hijos;
        ll raiz;
        cin >> raiz;
        for(int i=1;i<n;i++){
            ll valor;
            cin >> valor;
            padres.pb(valor);
        }
        for(int i=1;i<n;i++){
            ll valor;
            cin >> valor;
            hijos.pb(valor);
        }
        
        int minimo= (padres[0]+hijos[0]);
        forn(i,n-1){
            if(((padres[i]+hijos[i])<minimo)){
                minimo = (padres[i]+hijos[i]);
            }
        
        
        }
        cout << raiz+minimo << endl;
    }
}