#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
struct triple {
    int first;
    int second;
    int third;
};
int main(){
    freopen("input.txt","r",stdin);
    vector<vector<char>> tablero;
    int c, f;
    cin >> f >> c;
    forn(i, f){
        vector<char> aux;
        forn(j, c){
            char p;
            cin >> p;
            aux.push_back(p);
        }
        tablero.push_back(aux);
    }
    /*
    forn(i, f){
        forn(j, c){
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    */
    vector<triple> inters;
    int ans = 0;
    forn(i, f){
        int len=0, centro=0, vecinos=0, centroI=0, centroJ=0, comienzo=0;
        if(i-1<0 || i+1>f-1) continue;
        forn(j, c){
            if (tablero[i][j] == '.'){
                //if(len==5){cout << "centro: " << centro << " vecinos: " << vecinos << " comienzo: " << comienzo << endl;}
                if(len%2!=0 && centro==1 && vecinos==1 && len>1 && (len/2)+comienzo==centroJ){
                    ans++;
                    inters.push_back({centroI,centroJ,len/2});
                }
                len = 0;
                centro = 0;
                vecinos = 0;
            }else{
                if(len==0)comienzo=j;
                len++;
                //cout << "len: " << len << "inters: " << centro << endl;
                if (tablero[i+1][j] == '*' && tablero[i-1][j] == '*'){
                    centro++;
                    centroI=i;
                    centroJ=j;   
                }
                if ((tablero[i+1][j] == '*' || tablero[i-1][j] == '*') ){
                    vecinos++;
                }
            }
        }
        if (tablero[i][c-1] == '*'){
            if(len%2!=0 && centro==1 && vecinos==1 && len>1 && (len/2)+comienzo==centroJ){
                ans++;
                inters.push_back({centroI,centroJ,len/2});
            }
        }
        
    }
    int cruci=0;
    forn(i,inters.size()){
        int cruz=0;
        //para arriba
        for(int w=inters[i].first-1; w>=0; w--){
            if(tablero[w][inters[i].second]=='*'&& tablero[w][(inters[i].second)-1]=='.' && tablero[w][(inters[i].second)+1]=='.'){
                cruz++;
            }else{
                if(tablero[w][inters[i].second]=='*')cruz=0;
                break;
            }
        }
        //cout << cruz << endl;
        if(cruz!=inters[i].third)continue;
        cruz=0;
        //para abajo
        for(int w=inters[i].first+1; w<f; w++){
            if(tablero[w][inters[i].second]=='*'&& tablero[w][(inters[i].second)-1]=='.' && tablero[w][(inters[i].second)+1]=='.'){
                cruz++;
            }else{
                if(tablero[w][inters[i].second]=='*')cruz=0;
                break;
            }
        }
        //cout << cruz << endl;
        if(cruz<=inters[i].third)continue;
        else cruci++;
    }
    
    cout << cruci << endl;
    return 0;
}


