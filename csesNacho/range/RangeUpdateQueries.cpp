#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

#define operacion(x, y) (x+y)
#define neutro 0
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


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<ll> v(n),x(n);
    forn(i,n){
        cin >> x[i];
        if(i==0)v[i]=x[i];
        else v[i]=x[i]-x[i-1];
    }
    mx.init(v.size()); 
    forn(i, v.size()) mx[i]=v[i]; 
    mx.updall();
    forn(i,q){
        int opcion,a; 
        cin >> opcion >> a;
        a--;
        if(opcion==1){
            int b;ll u; 
            cin>> b >> u;
            b--;
            mx.set(a, mx.get(a,a+1)+u);
            mx.set(b+1,mx.get(b+1,b+2)-u);
        }else{
            cout << mx.get(0, a+1) << endl;
        }
    }
    

    return 0;
}