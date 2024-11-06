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

    ll x;
    int n;
    cin >> x >> n;
    ll p=0;
    
    map<ll,ll> l;
    l[0]++;
    l[x]++;
    map<ll,ll> maxs;
    forn(i,n){
        cin >> p;
        auto it = l.lower_bound(p);
        auto diff = it->first - prev(it)->first;

        if (maxs.count(diff) > 0) {
            maxs[diff]--; 
            if (maxs[diff] < 1) {  
                maxs.erase(diff);
            }
        }

        maxs[abs(p-prev(it)->first)]++;
        maxs[abs(p-(it->first))]++;
        l[p]++;
        
        cout << maxs.rbegin()->first << " ";
    }

    return 0;
}