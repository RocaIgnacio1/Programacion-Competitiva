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

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<pair<ll,int>> x;
    forn(i,n){
        ll a;
        cin >> a;
        x.pb(make_pair(a,i+1));
    }
    
    stack<pair<ll,int>> pila;
    int eliminados=0;
    forn(i,n){
        if(i==0){
            cout << 0 << " ";
        }else{
            while(pila.size()>0){
                if(pila.top().first < x[i].first){
                    cout << pila.top().second << " " ;
                    break;
                }else{
                    pila.pop();
                    eliminados++;
                }
            }
            if(pila.size()==0) cout << 0 << " ";
        }
        pila.push(make_pair(x[i].first,x[i].second));
    }
    
    return 0;
}