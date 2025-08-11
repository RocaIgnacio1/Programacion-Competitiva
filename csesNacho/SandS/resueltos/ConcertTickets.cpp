#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18+100;
const ll mod = 1000000007;
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    map<ll,int> h;
    vector<ll> t(m);
    forn(i,n){
        ll val; cin >> val;
        h[val]++;
    }
    forn(i,m)cin >> t[i];

    forn(i,m){
        auto it = h.upper_bound(t[i]);
        if(it == h.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << it->first << endl;
            h[it->first]--;
            if(h[it->first]==0)h.erase(it->first);
        }
    }

    return 0;
}