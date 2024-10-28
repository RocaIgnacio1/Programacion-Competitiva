
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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

#define MAXN 5000
#define operacion(x, y) x+y
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



struct triple{
    ll first, second, third;
};

bool sortBy(const triple &a, const triple &b){
    if(a.second==b.second) return a.third<b.third;
    return a.second<b.second;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<triple> x;
    map<int, int> pos;
    forn(i,n){
        ll t,d;
        cin >> t >> d;
        triple a;
        a.first = t;
        a.second = d;
        a.third = i+1;
        x.pb(a);
    }
    sort(x.begin(), x.end(),sortBy);
    mx.init(n); forn(i, n) mx[i] = 0; mx.updall();
    forn(i,n){
        mx.set(i, x[i].first);
        pos[x[i].third] = i;
    }

    forn(i, n){
        auto p = x[pos[n-i-1]];
        int l = 0, r = pos[n-i-1] - 1, mid = (l+r)/2;
        while(l <= r){
            auto abajo = mx.get(0, mid);
            if(val < v[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
            mid = (l+r)/2;
        }
        if(val < v[mid]){
            mid --;
        }
        
    }
    forn(i,n){
        cout << x[i].third << " ";
    }
    cout << endl;

    return 0;
}