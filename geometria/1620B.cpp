#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define mos(v) for(auto i : v) cout << i << " ";
typedef long long T;
typedef long double ld;
const T EPS = 1e-9;
const T INF = 1e18;

int main() {
    int t;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        ll w,h;
        cin >> w >> h;
        ll maximo=0,indice,altura,alturaMax=0;
        forn(i,4){
            ll c;
            cin >> c;
            //cout << c << endl;
            ll primero,ultimo;
            forn(j,c){
                ll valor;
                cin >> valor;
                //cout << valor << " ";
                if(j==0)primero=valor;
                if(j==c-1)ultimo=valor;
            }
            //cout << endl;
            if(i==0||i==1)altura=h;
            else altura=w;
            maximo = max(maximo, (ultimo-primero)*altura);
        }
        cout << maximo << endl;
    }
    return 0;
}
