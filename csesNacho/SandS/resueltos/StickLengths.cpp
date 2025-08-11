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
 
    int n;cin>>n;
    vector<ll> p(n);
    forn(i,n){
        cin >> p[i];
    }
    
    ll val1=0, val2=0;
    sort(p.begin(),p.end());
    val2 = p[(n/2)-1];
    val1 = p[(n/2)];
    ll ans1=0, ans2=0;
    forn(i,n){
        ans1+=abs(p[i]-val1);
        ans2+=abs(p[i]-val2);
    }
    cout << min(ans1,ans2) << endl;
    
    return 0;
}