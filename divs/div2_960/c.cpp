
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main() {
    freopen("input.txt", "r", stdin);
    int n, x, y,t;
    cin >> t;
    forn(w,t){

    
        cin >> n ;
        map<int,int> a;
        int maximo=0;
        int suma=0;
        forn(i,n){
            int valor;
            cin >> valor;
            a[valor]++;
            suma+=valor;

            if((a[valor]>=2 && valor>maximo) || i==n-1){
                if(maximo!=0){
                    int apariciones = ((a[maximo])*(a[maximo]-1))/2;
                    //cout << apariciones*maximo << endl;
                    suma += apariciones*maximo;
                }
                maximo=valor;
            }
        }
        int apariciones = ((a[maximo])*(a[maximo]-1))/2;
        //cout << apariciones*maximo << endl;
        suma += apariciones*maximo;
        cout << suma << endl;
        
    }
    return 0;
}
