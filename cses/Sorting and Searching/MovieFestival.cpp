#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif

vector<pair<ll,ll>> t;
bool sortby(const pair<ll,ll> &a, const pair<ll,ll> &b){
   return (a.second < b.second);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<pair<ll,ll>> p;

    forn(i,n){
        ll a,b;
        cin >> a >> b;
        p.push_back(make_pair(a,b));
    }
    sort(p.begin(),p.end(),sortby);
    int ans=1;
    ll anterior=0;
    forn(i,n){
       if(i==0){
            anterior = p[i].second;
            continue;
       }
       if(p[i].first>=anterior){
            //cout << p[i].first << " " << p[i].second << endl;
            anterior = p[i].second;
            ans++;
       }
    }
    cout << ans << endl;
    
}