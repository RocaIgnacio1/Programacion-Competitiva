#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define pb push_back
#define pp pop_back
#define F first
#define S second
const int mod=1e9+7;
const int MAX=3e5+10;
const ll INF = 1e18+100;
typedef long double ld;
const ld EPS = 1e-9;


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<ll> a(n);
        ll max=0;
        int indice=0;
        forn(i,n){
            cin >> a[i];
            if(a[i]>=max){
                max=a[i];
                indice=i;
            }
        }
        
        vector<ll> ans;
        forn(i,m){
            char c;
            ll x,y;
            cin >> c >> x >> y;
            if(c=='+'){
                if(x<=max && max<=y){
                    max++;    
                }
            }else{
                if(x<=max && max<=y){
                    max--;   
                }
            }
            ans.pb(max);
        }
        
        forn(i,ans.size()){
            cout << ans[i] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
