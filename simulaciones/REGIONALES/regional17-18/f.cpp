#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define MAXN 1000000008
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> inp;
    map<int, ll> m;
    forn(i, n){
        ll x,y, z;
        cin >> x >> y >> z;
        inp.push_back(make_pair(x,y));
        m[y] += z;
        cout << y << " " << z << endl << endl;
    }
    ll acum = 0;
    for(auto i = (m.end())--; i != (m.begin())--; i--){
        cout << i->first << " " << i->second << endl;
        acum += i->first;
        i->second = acum;
    }

    for(auto i: m){
        cout << i.first << " " << i.second << endl;
    }
    sort(inp.begin(), inp.end());

}