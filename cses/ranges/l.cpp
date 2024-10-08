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
#define neutro make_pair(1e9+2, 0)
#define tipo pair<int, int>

pair<int, int> operacion(tipo x, tipo y){
    int a = x.first + y.second;
    int b = y.first;
    if(a>b){
        return make_pair(b, y.second + x.second);
    }else{
        return make_pair(a, y.second + x.second);
    }
}

pair<int, int> operacion2(tipo x, tipo y){
    int a = x.first;
    int b = y.first + x.second;
    if(b>a){
        return make_pair(a, y.second + x.second);
    }else{
        return make_pair(b, y.second + x.second);
    }
}
 
struct RMQIZ{
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
}miz;

struct RMQDE{
    int sz;
    tipo t[4*MAXN];
    tipo &operator[](int p){return t[sz+p];}
    void init(int n){//O(nlgn)
        sz = 1 << (32-__builtin_clz(n));
        forn(i, 2*sz) t[i] = neutro;
    }
    void updall(){
        dforn(i, sz) t[i] = operacion2(t[2*i], t[2*i+1]);
    }
    tipo get(int i, int j){return get(i, j, 1, 0, sz);}
    tipo get(int i, int j, int n, int a, int b){
        if(j<=a || i>= b) return neutro;
        if(i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return operacion2(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, tipo val){
        for(p+=sz; p>0 && t[p] != val;){
            t[p]=val;
            p/=2;
            val = operacion2(t[2*p],t[2*p+1]);
        }
    }
}mde;
 
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
        
        miz.init(piz.size()); forn(i, piz.size()) miz[i] = make_pair(piz[i], 1); miz.updall();
        mde.init(piz.size()); forn(i, piz.size()) mde[i] = make_pair(piz[i], 1); mde.updall();

        forn(i, q){
            int w;
            cin >> w;
            if(w == 1){
                int a, b;
                cin >> a >> b;
                miz.set(a-1, make_pair(b, 1));
                mde.set(a-1, make_pair(b, 1));
            }else{
                int a;
                cin >> a;
                cout << min(miz.get(0, a), mde.get(a-1, piz.size()+1)).first << '\n';
            }
        }

 
 
    return 0;
}