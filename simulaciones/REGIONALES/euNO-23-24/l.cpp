#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int n, m;
void mos(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < n){
        string p;
        cout << x+1 << " " << y+1 << endl;
        cin >> p;
    } 
}

void comprobar_resto(int x, int y){
    mos(x, y-1);
    mos(x, y-2);
    mos(x, y-3);
    mos(x, y-4);
    mos(x, y+1);
    mos(x, y+2);
    mos(x, y+3);
    mos(x, y+4);
    mos(x-1, y);
    mos(x-2, y);
    mos(x-3, y);
    mos(x-4, y);
    mos(x+1, y);
    mos(x+2, y);
    mos(x+3, y);
    mos(x+4, y);
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n >> m;
    for(int i = 0; i<n; i+=5){
        int aux1 = i, aux2 = 0;
        while(aux1 < n && aux2 < n){
            string res;
            cout << aux1+1 << " " << aux2+1 << '\n';
            cout.flush();
            cin >> res;
            if(res == "hit"){
                comprobar_resto(aux1, aux2);
            }
            aux1+=1; aux2+=1;
        }
    }

    for(int i = 5; i<n; i+=5){
        int aux1 = 0, aux2 = i;
        while(aux1 < n && aux2 < n){
            string res;
            cout << aux1+1 << " " << aux2+1 << '\n';
            cout.flush();
            cin >> res;
            if(res == "hit"){
                comprobar_resto(aux1, aux2);
            }
            aux1++; aux2++;
        }
    }

}