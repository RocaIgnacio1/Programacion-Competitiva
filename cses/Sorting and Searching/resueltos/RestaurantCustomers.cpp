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

vector<pair<ll,int>> t;
bool sortby(const pair<ll,int> &a, const pair<ll,int> &b){
    if(a.first==b.first){
        return (a.second<b.second);
    }
    else return (a.first < b.first);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    forn(i,n){
        ll a,b;
        cin >> a >> b;
        t.push_back(make_pair(a,1));
        t.push_back(make_pair(b,0));
    }
    sort(t.begin(),t.end(),sortby);
    int ans=0,acum=0;
    forn(i,2*n){
        if(t[i].second==1)acum++;
        else acum--;

        ans = max(ans,acum);
    }
    cout << ans << endl;
    
}