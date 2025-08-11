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

    ll x;cin>>x;
    ll l=0,r=x;
    int n;cin>>n;
    map<ll,int> luces, res;
    luces[l]++;
    luces[r]++;
    ll ans=0;
    forn(i,n){
        ll p; cin >> p; luces[p]++;
        auto it1 = luces.find(p), it2 = it1;
        it1++; it2--;
        ll eliminar = abs(it1->first - it2->first);
        res[eliminar]--;
        if(res[eliminar]<=0)res.erase(eliminar);
        
        ll val1 = abs(it1->first - p), val2 = abs(it2->first - p);
        res[val1]++;
        res[val2]++;
        cout << prev(res.end())->first << " ";
    }
    cout<<endl;
    return 0;
}