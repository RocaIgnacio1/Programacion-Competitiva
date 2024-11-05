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
struct pto{
    int x,y;
    pto(int _x, int _y) : x(_x) , y(_y) {}
    int operator^(pto b) {return x*b.y-y*b.x ;}
};


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int t;
    cin >> t;

    forn(i,t){
        
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;

        pto uno(c-a,d-b);
        pto dos(e-a,f-b);

        //cout << "hola" << " "  << i <<  endl;
        if((uno^dos) < 0){
            cout << "DERECHA" << endl;
        }else{
            if((uno^dos) > 0){
                cout << "IZQUIERDA" << endl;
            }else{
                cout << "RECTO" << endl;
            }
        }


    }
    
    return 0;
}
