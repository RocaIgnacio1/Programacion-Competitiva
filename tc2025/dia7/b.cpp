#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;
const ll MAXN = 10000000000;
 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    int t;
    cin >> t;
    forn(k,t){
        int n;
        cin >> n;
        vector<vector<ll>> numeros;
        forn(i,n){
            vector<ll> p(n);
            forn(j,n){
                cin >> p[j];
            }
            numeros.push_back(p);
        }

        ll derecha=MAXN;
        for(int i=((n/2)+1); i<n; i++){
            derecha = min(derecha, numeros[n/2][i]);
        }

        ll izquierda=MAXN;
        for(int i=0; i<(n/2); i++){
            izquierda = min(izquierda, numeros[n/2][i]);
        }

        ll arriba=MAXN;
        for(int i=0; i<(n/2); i++){
            arriba = min(arriba, numeros[i][n/2]);
        }

        ll abajo=MAXN;
        for(int i=((n/2)+1); i<n; i++){
            abajo = min(abajo, numeros[i][n/2]);
        }
        //cout << izquierda << " " << derecha << " " << arriba << " " << abajo << endl;
        
        ll res=0;
        ll a=MAXN;
        for(int i=0; i<=(n/2); i++){
            for(int j=0; j<=(n/2); j++){
                a = min(a, numeros[i][j]);
            }
        }
        ll b=MAXN;
        for(int i=0; i<=(n/2); i++){
            for(int j=(n/2); j<n; j++){
                b = min(b, numeros[i][j]);
            }
        }
        ll c=MAXN;
        for(int i=(n/2); i<n; i++){
            for(int j=0; j<=(n/2); j++){
                c = min(c, numeros[i][j]);
            }
        }
        ll d=MAXN;
        for(int i=(n/2); i<n; i++){
            for(int j=(n/2); j<n; j++){
                d = min(d, numeros[i][j]);
            }
        }

        ll forma1 = min(a+c,izquierda)+min(b+d,derecha);
        ll forma2 = min(a+b,arriba)+min(c+d,abajo);
        cout << min(min(forma1,forma2),numeros[n/2][n/2]) << endl;
        
    }
   
    return 0;
}
