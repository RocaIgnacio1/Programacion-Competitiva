#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll inf = 1e18+100;
const ll mod = 1e9+7;
const ll MAXN = 2e5+100;
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)


#ifdef EBUG
#else
#endif

 
int const ST_LEN = 1 << 19; // 2 elevado a la 20
pair<ll,ll> st[ST_LEN*2];
 
void init() {
	for (int i = 1; i < 2*ST_LEN; ++i) st[i] = {0,0};
}
 
int ql, qr;
 
pair<ll,ll> query_aux(int i, int l, int r) {
	if (ql <= l && r <= qr) return st[i];
	
	if (qr <= l || r <= ql) return {0,0};
 
	int m = (l+r)/2;
	pair<ll,ll> p1=query_aux(i*2,l,m), p2=query_aux(i*2+1,m,r);
	return {p1.F + p2.F, max(p1.S, p1.F + p2.S)};
}
 
pair<ll,ll> query(int l, int r) {
	ql = l; qr = r;
	return query_aux(1, 0, ST_LEN);
}
 
void update(int i, ll x) {
	i += ST_LEN;
	st[i] = {x,max((ll)0,x)};
	while (i /= 2) st[i] = {st[i*2].F + st[i*2+1].F,
							max(st[i*2].S, st[i*2].F + st[i*2+1].S)};
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
	ll n,q,a,b,x; cin>>n>>q;
	init();
	for(int i=1;i<=n;i++) cin>>x, update(i,x);
	
	while(q--){
		cin>>x>>a>>b;
		if(x==1) update(a,b);
		else cout<<query(a,b+1).S<<"\n";
	}
    return 0;
}