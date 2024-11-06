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
#define tipo pair<ll, int>
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

vector<ll> v, diff;
set<int> mayores;
int n;
void solve(int pos){
    auto r = mayores.upper_bound(pos);
    auto l = mayores.lower_bound(pos);
    //cout << pos << endl;
    //cout << *l << " " << *r << endl;
    if(l == mayores.begin()){
        //cout << "hola" << endl;
        diff[0]+=1;
        diff[pos]-=1;
    }else{
        l--;
        int p = *l;
        if(((p+pos)/2)+1 < pos){
            diff[((p+pos)/2)+1]+=1;
            diff[pos]-=1;
        }
    }
    if(r == mayores.end()){
        diff[pos+1]+=1;
        diff[n]-=1;
    }else{
        int p = *r;
        if((p+pos)/2 + (p+pos)%2 - 1 >= pos){
            diff[(p+pos)/2 + (p+pos)%2]-=1;
            diff[pos+1]+=1;
        }
    }
    mx.set(pos, make_pair(0, pos));
    mayores.insert(pos);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    forn(i, n){
        ll p;
        cin >> p;
        v.pb(p);
        diff.pb(0);
    }
    diff.pb(0);
    mx.init(v.size()); forn(i, v.size()) mx[i] = make_pair(v[i], i); mx.updall();
    forn(i, n){
        solve(mx.get(0, n).second);
    }
    int acum = 0;
    forn(i, n){
        acum += diff[i];
        cout << acum << " ";
    }
    
    return 0;
}
