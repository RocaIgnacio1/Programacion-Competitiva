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
    vector<ll> t(n);
    forn(i,n){
        cin >> t[i];
    }
    ll torres=0;
    map<ll,ll> vals;
    forn(i,n){
        auto it = vals.upper_bound(t[i]);
        if (it != vals.end()) {
            vals[it->first]--;
            if(vals[it->first]==0)vals.erase(it->first);
        }else{
            torres++;
        }
       
        vals[t[i]]++;
    }
    cout << torres << endl;
    return 0;
}
