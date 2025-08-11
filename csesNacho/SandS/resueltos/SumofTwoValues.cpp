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
    
    int n; cin>>n;
    ll x; cin >>x;
    vector<pair<ll,int>> a;
    forn(i,n){
        ll num; cin >> num;
        a.push_back(make_pair(num,i+1));
    }
    sort(a.begin(), a.end());
    int i=0, j=n-1;
    while(i<j){
        if(a[i].first+a[j].first == x){
            cout << min(a[i].second,a[j].second) <<" "<< max(a[i].second, a[j].second) << endl;
            i=j;
            return 0;
        }else{
            if(a[i].first+a[j].first>x)j--;
            else i++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}