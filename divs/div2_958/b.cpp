#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#include <math.h>


int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    forn(i,t){
        int n;
        cin >> n;
        int unos=0;
        int ceros=0;
        char anterior='1';
        string cadena;
        cin >> cadena;
        
        forn(j,n){
            if(cadena[j]=='1'){
                unos++;
            }else{
                if(anterior=='1')ceros++;
            }

            anterior=cadena[j];
        }
        //cout << "ceros: " << ceros << " " << "unos: " << unos << endl;
        if(ceros<unos){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
}