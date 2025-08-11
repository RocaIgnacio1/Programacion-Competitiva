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
    
    int n;
    ll x;
    cin >> n >> x;
    deque<ll> p(n);
    forn(i,n)cin >> p[i];
    sort(all(p));
    int res=0;
    while(p.size()>=2){
        if(p.front()+p.back() <= x){
            p.pop_front();
            p.pop_back();
            res++;
            continue;
        }
        if(p.back()<= x)res++;
        p.pop_back();
    }
    if(p.size()==1 && p.front()<=x)res++;
    cout << res << endl;
    return 0;
}