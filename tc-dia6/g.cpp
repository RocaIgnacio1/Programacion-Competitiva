#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    int n,r;
    //freopen("input.txt", "r", stdin);
    cin >> n >> r;
    int curling[n];
    ld valores[n];

    forn(i,n){
        int valor;
        cin >> valor;
        curling[i]=valor;
    }
    valores[0]=r;
    for(int i=1;i<n;i++){
        valores[i]=r*1.0;
        for(int j=0; j<i; j++){
            ld rta=0;
            if(i==j)continue;
            if(curling[i] == curling[j]){
                //cout << "uno encima del otro" << endl;
                rta = valores[j] + 2*r;  
                valores[i] = max(valores[i],rta);
                
            }
            if(curling[i]-r == curling[j]-r || curling[i]-r == curling[j]+r || curling[i]+r == curling[j]-r || curling[i]+r == curling[j]+r){
                //cout << "uno al lado del otro" << endl;
                rta = valores[j];
                valores[i] = max(valores[i],rta);
                
            }
            if( (curling[i]-r > curling[j]-r && curling[i]-r < curling[j]+r)|| (curling[i]+r > curling[j]-r && curling[i]+r < curling[j]+r)){
                //cout << "chocan" << endl;
                int cateto = abs(curling[i]-curling[j]);
                rta = sqrt((4*r*r) - (cateto*cateto)) + valores[j];
                valores[i] = max(valores[i],rta);
                
            }
        }
        
    }

    forn(i,n){
        cout << setprecision(10) <<  valores[i] << " ";
    }
}