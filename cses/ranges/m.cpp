#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll inf = 1e18+100;
const ll mod = 1e9+7;
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
 
#define MAXN 200000
#define neutro make_tuple(-1e9+3, -1e9+3, -1e9+3)
#define tipo tuple<ll, ll, ll>

tipo operacion(tipo x, tipo y){
    if(x == neutro) return y;
    if(y == neutro) return x;
    ll x0 = get<0>(x);
    ll x1 = get<1>(x);
    ll x2 = get<2>(x);
    ll y0 = get<0>(y);
    ll y1 = get<1>(y);
    ll y2 = get<2>(y);

    if(x1+x2+y0+y1 >= x1 && x1+x2+y0+y1 >= y1) return make_tuple(x0, x1 + x2 + y0 + y1, y2);
    if(x1 >= y1 && x1>= x1+x2+y0+y1) return make_tuple(x0, x1, x2+y0+y1+y2);
    return make_tuple(x0 + x1 + x2 + y0, y1, y2);
}
 
struct RMQ{
    int sz;
    tipo t[4*MAXN];
    tipo &operator[](int p){return t[sz+p];}
    void init(int n){//O(nlgn)
        sz = 1 << (32-__builtin_clz(n));
        forn(i, 2*sz) t[i] = neutro;
    }
    void updall(){
        dforn(i, sz) t[i] = operacion(t[2*i], t[2*i+1]);
    }
    tipo get(int i, int j){return get(i, j, 1, 0, sz);}
    tipo get(int i, int j, int n, int a, int b){
        if(j<=a || i>= b) return neutro;
        if(i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, tipo val){
        for(p+=sz; p>0 && t[p] != val;){
            t[p]=val;
            p/=2;
            val = operacion(t[2*p],t[2*p+1]);
        }
    }
}sum;
 
#include <bits/stdc++.h>
using namespace std;

int main(){
        #ifdef EBUG
            freopen("input.txt", "r", stdin);
        #endif
        ios :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n, q;
        cin >> n >> q;
        vector<int> piz;
        forn(i, n){
            int p;
            cin >> p;
            piz.push_back(p);
        }
        sum.init(piz.size()); forn(i, piz.size()) sum[i] = make_tuple(0, piz[i], 0); sum.updall();
        forn(i, q){
            int w, g;
            cin >> w >> g;
            sum.set(w-1, make_tuple(0, g, 0));
            cout << get<1>(sum.get(0, n+1)) << "\n";
        }

        forn(i, 10){
            cout << get<0>(sum.get(i, i+4)) << " "<< get<1>(sum.get(i, i+4)) << " "<< get<2>(sum.get(i, i+4)) << " " << endl;
        }cout << endl;
        
    return 0;
}