#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;
const ll MAXN = 10000000000;
 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    int t;
    cin >> t;
    forn(k,t){
        int n,m;
        cin >> n >> m;
        vector<ll> baterias(n);
        ll total=0;
        forn(i,n){
            cin >> baterias[i];
            total+=baterias[i];
        }
        vector<pair<ll,ll>> estaciones(m);
        forn(i,m){
            cin >> estaciones[i].first >> estaciones[i].second;
        }
        ll actual=total, res=0;
        forn(i,m){
            
            if((actual- (estaciones[i].first-estaciones[i-1].first)<0)){
                res += actual;
                actual=0;
                break;
            }else{
                if(i==0)actual-= estaciones[i].first;
                else{actual-= (estaciones[i].first-estaciones[i-1].first);}
                cout << actual << endl;
                actual = min(total, actual+baterias[estaciones[i].second-1]);
                cout << actual << endl;
                res=estaciones[i].first;
            }
            //cout << actual << endl;
        }
        cout << res+actual << endl;
    }
   
    return 0;
}
