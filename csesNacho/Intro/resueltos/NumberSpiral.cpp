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
    
    int t; cin >> t;

    forn(i,t){
        ll y,x;
        cin >> y >> x;

        ll bloque = max(y,x);

        ll empieza = (bloque-1) * (bloque-1);

        if(bloque%2!=0){
            //empieza desde la izquierda
            if(y==bloque){
                cout << empieza+x << endl;
            }else{
                cout << (bloque*bloque)-y+1 << endl;
            }

        }else{
            //empieza desde la derecha
            if(x==bloque){
                cout << empieza+y << endl;
            }else{
                cout << (bloque*bloque)-x+1 << endl;
            }

        }
    }
    


    return 0;
}
