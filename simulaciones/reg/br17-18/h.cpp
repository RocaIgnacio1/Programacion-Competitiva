#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back
typedef long long ll;
#ifdef EBUG
//local
#else
//judge
#endif

#define MAXN 100000
#define operacion(x, y) max(x, y)
#define tipo pair<int, int>
const tipo neutro = make_pair(0, -1);


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
    int n, k;
    cin >> n >> k;
    vector<int> v;
    forn(i, n){
        int p;
        cin >> p;
        v.push_back(p);
    }
    mx.init(v.size()); forn(i, v.size()) mx[i] = make_pair(v[i], i); mx.updall();
    int tope = n/(k+1);
    int acum = 0;
    pair<int, int> x;
    //cout << tope << endl;
    forn(i,tope){
        //cout << ((k+1)*(tope-i)-1) << " " << n << endl;
        x = mx.get((k+(k+1)*(tope-i-1)), n);
        mx.set(x.second, make_pair(0, x.second));
        v[x.second] = 0;
    }
    ll res = 0;
    forn(i, n){
        res += v[i];
        //cout << v[i] << " ";
    }//cout << endl;
    cout << res << endl;
    
    
    return 0;
}