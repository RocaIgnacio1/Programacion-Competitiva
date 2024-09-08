#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;


#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    for(int i=1;i<10;i++){
        forn(j,10){
            forn(k,10){
                forn(p,10){
                    ll num = i*100000000 + j*10000000 + k*1000000 + p*100000 + 1000;
                    if(num%17==0){
                        cout << num << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    
    return 0;
}