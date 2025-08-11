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
    vector<pair<ll,ll>> c;
    forn(i,n){
        ll a,b;
        //1 llegada. 0 salida;
        cin >> a >> b;
        c.push_back(make_pair(a,1));
        c.push_back(make_pair(b,0));
    }
    sort(c.begin(),c.end());
    int con=0, ans=0;
    forn(i,2*n){
        if(c[i].second == 1)con++;
        if(c[i].second == 0)con--;
        ans = max(ans, con);
    }
    cout << ans << endl;

    return 0;
}