#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define ll long long
ll MOD = 1000000000+7;
#define cuent(a,b) (a*b)%MOD
#define MAXN 10000
#define operacion(x, y) cuent(x,y)
#define neutro 1
#define tipo ll

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
}mx;



ll sigma(ll n){
    ll res = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            res += i;
            if(i*i != n){
                res += n/i;
            }
        }
    }

    return res;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n, q;
    vector<ll> a;
    cin >> n >> q;
    forn(i, n){
        ll f;
        cin >> f;
        a.push_back(sigma(f));
    }
    mx.init(a.size()); forn(i, a.size()) mx[i] = a[i]; mx.updall();
    forn(i, q){
        int l, r;
        cin >> l >> r;
        cout << mx.get(l-1, r) << '\n';
    }
}
