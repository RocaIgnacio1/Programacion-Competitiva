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

bool comp(pair<ll,ll> &a, pair<ll,ll>&b){
    if(a.second != b.second)return a.second<b.second;
    else return a.first<b.first;
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    vector<pair<ll,ll>> movies;
    forn(i,n){
        ll a,b;
        cin >> a >> b;
        movies.push_back(make_pair(a,b));
    }

    sort(movies.begin(), movies.end(), comp);
    //forn(i,n)cout << movies[i].second << " " << movies[i].first << endl;

    int ans=0, anterior=0;
    forn(i,n){
        if(movies[i].first>=anterior){
            ans++;
            anterior = movies[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}