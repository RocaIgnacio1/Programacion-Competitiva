#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#define MAXN 200000

#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    vector<ll> X;
    vector<ll> P;
    vector<tuple<ll, ll, ll>> inters;
    set<ll> heladerias;

    int n, m;
    cin >> n >> m;
    forn(i, n){
        ll p;
        cin >> p;
        P.push_back(p);
    }
    forn(i, m){
        ll x;
        cin >> x;
        X.push_back(x);
        heladerias.insert(x);
    }
    forn(i, n){
        auto p1 = lower_bound(X.begin(), X.end(), i*100);
        auto p2 = upper_bound(X.begin(), X.end(), i*100);
        cout << i << ": " << *p1 << " " << *p2 << endl;
        if (p1 == X.end()) p1 = X.end() - 1;
        if (p2 == X.end()) p2 = X.end() - 1;
        ll r = min(abs(*p1-i*100), abs(*p2-i*100));
        inters.push_back({i*100-r, i*100+r, P[i]});
    }

    for (auto in : inters) {
        cout << get<0>(in) << ", " << get<1>(in) << ": " << get<2>(in) << endl;
    }


    ll max_ice = 0;
    ll acum = 0;
    ll x1 = get<0>(inters[0]);   ll y1 = get<1>(inters[0]);  ll p1 = get<2>(inters[0]);
    acum += p1;
    for (int i = 1; i < inters.size(); i++) {
        x1 = get<0>(inters[i-1]);    y1 = get<1>(inters[i-1]);  p1 = get<2>(inters[i-1]);
        ll x2 = get<0>(inters[i]); ll y2 = get<1>(inters[i]); ll p2 = get<2>(inters[i]);
        if (x2 <= y1 && x2 >= x1) {
            if(y2 == y1){
                acum += p2;
            }
            if(x2 == x1){
                acum += p2;
            }
            if (y1 <= x2 || (heladerias.find(y1) == heladerias.end() &&
                heladerias.find(y2) == heladerias.end())){
                max_ice = max(max_ice, acum);
                acum = p2;
            }
        }
    }
    x1 = get<0>(inters[inters.size()-1]);   y1 = get<1>(inters[inters.size()-1]); p1 = get<2>(inters[inters.size()-1]);
    max_ice = max(max_ice, acum);
    acum = 0;
    acum = 0;
    x1 = get<0>(inters[0]);   y1 = get<1>(inters[0]);p1 = get<2>(inters[0]);
    acum += p1;
    cout << max_ice << endl;

    return 0;
}