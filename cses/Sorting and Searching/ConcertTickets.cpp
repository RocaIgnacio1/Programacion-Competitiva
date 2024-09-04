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

map<ll,int> h;


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n,m;
    cin >> n >> m;
    vector<ll> t;
    
    forn(i,n){
        ll a;
        cin >> a;
        h[a]++;
    }
    forn(i,m){
        ll a;
        cin >> a;
        t.push_back(a);
    }

    forn(i,m){
        //primero en pasar el precio.
        map<ll,int>::iterator up = h.upper_bound(t[i]);
        if(up == h.begin()){
            //si es el primero del map -> no tiene anterior
            cout << -1 << endl;
        }else{
            //si no es el primero del map, devuelvo el anterior
            up--;
            cout << up->first << endl;
            h[up->first]--;
            if (h[up->first] == 0)h.erase(up);
            
        }
    }
    
}