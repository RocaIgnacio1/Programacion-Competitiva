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
        int n,m;
        vector<ll> a;
        vector<ll> b;
        cin >> n >> m;
        
        forn(i,n){
            ll valor;
            cin >> valor;
            a.pb(valor);
        }
        
        bool bandera=true;
        forn(i,m){
            ll valor;
            cin >> valor;
            // ingresar un 0
            if(valor>0 && bandera){
                b.pb(0);
                bandera=false;
            }
            b.pb(valor);           
        }
        if(bandera)b.pb(0);
        
        int j=n-1;
        while(j>=0){
            if(a[j]>b[m])j--;
            else break;
        }
        int especial=0, ans=0;
        for(int i=m; b[i]>0; i--){
            int suma=0;
            while(a[j]>b[i-1] && a[j]<=b[i] && j>=0){
                suma++;
                j--;
            }
            
            if(suma==0) especial++;
            else{
                ans++;
                suma--;
                if(especial>0)ans+= min(especial,suma);
                especial=0;
            }
            //cout << "Suma: " << suma << " Especial: " << especial << " Ans: " << ans << endl;
        }   
        j=0;
        while(j<n){
            if(a[j]<b[0])j++;
            else break;
        }
        
        especial=0;
        for(int i=0; b[i]<0; i++){
            int suma=0;
            //cout << a[j] << " " << b[i] << " " << b[i+1] << " " << j << " " << n<< endl;
            while(a[j]>=b[i] && a[j]<b[i+1] && j<n){
                suma++;
                j++;
            }
            
            if(suma==0) especial++;
            else{
                ans++;
                suma--;
                if(especial>0)ans+= min(especial,suma);
                especial=0;
            }
            //cout << "Suma: " << suma << " Especial: " << especial << " Ans: " << ans << endl;
        }   
        
        cout << ans << endl;
        
    }
    return 0;
}
