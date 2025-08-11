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
    
    int n; cin >> n;
    map<ll,int> x;
    forn(i,n){
        ll val; cin >> val;
        x[val]=i;
    }

    int anterior=0, ans=1;
    forn(i,n){
        if(x[i+1]<=anterior && i!=0){
            ans++;
        }
        anterior=x[i+1];
    }
    cout << ans << endl;
    return 0;
}