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

struct triple{
    ll first, second, third;
};

bool sortBy(const triple &a, const triple &b){
    if(a.first==b.first) return (a.second<b.second);
    
    return (a.first<b.first);
}
bool sortBy2(const pair<ll,int> &a, const pair<ll,int> &b){
    return (a.second<b.second);
}


int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<triple> t;
    forn(i,n){
        ll a, b;
        cin >> a >> b;
        triple c;
        c.first=a;
        c.second=b;
        c.third=i;
        t.pb(c);
    }
    sort(t.begin(),t.end(),sortBy);
    
    map<ll, set<ll>> h;
    int hab=0;
    vector<pair<ll,int>> ans(n);
    forn(i, n) {
        auto it = h.lower_bound(t[i].first);  

        if (it != h.begin()) {  
            --it;
            if (!it->second.empty()) {  
                ll room = *it->second.begin();
                ans[i] = make_pair(room, t[i].third);
                h[t[i].second].insert(room);
                it->second.erase(it->second.begin());
                if (it->second.empty()) {
                    h.erase(it);
                }
            }
        }else{
            hab++;
            ans[i] = make_pair(hab, t[i].third);
            h[t[i].second].insert(hab);
        }
    }
    cout << hab << endl;
    sort(ans.begin(), ans.end(), sortBy2);
    forn(i,n){
        cout << ans[i].first << " ";
    }
    cout << endl;
    return 0;
}