#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
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

    int n;
    cin >> n;
    vector<ll> c(n);

    forn(i,n){
        cin >> c[i];
    }
    sort(c.begin(),c.end());
    ll acumulado=0;
    forn(i,n){
        if(c[i]>acumulado+1){
            cout << acumulado+1 << endl;
            return 0;
        }else{
            acumulado+=c[i];
        }
    }
    cout << acumulado+1 << endl;
    return 0;    
}