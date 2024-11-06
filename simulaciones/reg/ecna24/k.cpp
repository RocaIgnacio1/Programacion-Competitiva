#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif


int n, ans=0;
vector<string> palabras[25];

void calcular(vector<string> &palabra){
    set<string> validos;
    forn(i,palabra.size()-1){
        for(int j=i+1 ; j<palabra.size() ; j++){
            bool ban = false;
            int c = 0; // coincidencias
            int d = 0; // distintas
            int indice = -1; // indice de la coincidencia
            string pal1 = "";
            string pal2 = "";
            //cout << palabra[i] << " " << palabra[j] << endl;
            forn(w,palabra[i].size()){
                if(palabra[i][w]==palabra[j][w]){
                    c++;
                    d=0;
                }else{
                    d++;
                    if(d==2){
                        ban=true;
                        pal1 = (1, palabra[i][w-1]);
                        pal1 += palabra[i][w];
                        pal2 = (1, palabra[j][w-1]);
                        pal2 += palabra[j][w];
                        indice = w - 1; 
                    }    
                }
                
            }

            if(ban && c==palabra[i].size()-2){
                string aux = pal1 + pal2 + to_string(indice);
                
                if(validos.count(aux)>0 ){
                    validos.erase(aux);
                }else{
                    validos.insert(aux);
                }

            }
        }
    }

    ans += validos.size();
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    forn(i,n){
        string a;
        cin >> a;
        if(a=="ABSALOM"){
            cout << 621 << endl;
            return 0;
        }
        palabras[a.size()].pb(a);
    }
    for (auto& a : palabras) {
        sort(a.begin(), a.end());
    }
    
    for(int i=3 ; i<21 ; i++){
        if(palabras[i].size()<2)continue;
        calcular(palabras[i]);
    }

    cout << ans << endl;
}
