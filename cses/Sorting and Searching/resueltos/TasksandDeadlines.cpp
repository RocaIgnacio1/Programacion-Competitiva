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

bool sortBy(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first==b.first) return (a.second<b.second);
    
    return (a.first<b.first);
}

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<pair<int,int>> t;
    forn(i,n){
        int a,d;
        cin >> a >> d;
        t.pb(make_pair(a,d));
    }

    sort(t.begin(),t.end(),sortBy);
    /*
    forn(i,n){
        cout << t[i].first << " " << t[i].second << endl;
    }
    */
    ll tiempo=0, ans=0;
    forn(i,n){
        tiempo+=t[i].first;
        ans+= (t[i].second-tiempo);
    }
    cout << ans << endl;
    return 0;
}