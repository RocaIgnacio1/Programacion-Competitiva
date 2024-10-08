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
 
map<ll, map<ll, ll>> dp, D;
vector<pair<ll, ll>> inp;
map<ll, ll> C;
vector<vector<ll>> B, F;
 
#define MAXN 200000
#define operacion(x, y) max(x, y)
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
 
 
void ingresar(vector<pair<ll, ll>> &inp, vector<vector<ll>> &B){
    sort(inp.begin(), inp.end());
    vector<ll> aux;
    aux.push_back(inp.begin()->second);
    for(auto it = inp.begin() + 1; it != inp.end(); it++){
        if(it-> first != (it-1)->first){
            B.push_back(aux);
            aux.clear();
        }
        aux.push_back(it->second);
    }
    B.push_back(aux);
}
 
 
map<ll, ll> faux, caux, maxFila;
void solve2(){
    forn(i, F[F.size()-1].size()){
        maxFila[faux[i]] = D[F.size()-1][i];
    }
    for(auto i = ((F.end())--)--; i != (F.begin())--; i--){
        
    }
}
 
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    set<ll> f, c;
    ll n;
    cin >> n;
    forn(i, n){
        ll x,y, z;
        cin >> x >> y >> z;
        f.insert(x);
        c.insert(y);
        inp.push_back(make_pair(x,y));
        C[i] = z;
    }
    int i = 0;
    for(auto j: f){
        faux[j] = i;
        i++;
    }
    i = 0;
    for(auto j: c){
        caux[j] = i;
        maxFila[j] = 0;
        i++;
    }
    forn(i, n){
        ll x = faux[inp[i].first];
        ll y = caux[inp[i].second];
        if(D[x][y] == 0) inp[i] = make_pair(x, y);
        D[x][y]+= C[i];
        dp[x][y] = -1;
    }
    ingresar(inp, B);
    reverse(B.begin(), B.end());
    int p = B.size();
    n = c.size();
    mx.init(n); forn(i, n) mx[i] = 0; mx.updall();
    /* for(auto i: D){
        for(auto j: i.second){
            cout << i.first << " " << j.first << " | " << j.second << endl;
        }
    } */
    forn(i, B.size()){
        for(auto j: B[i]){
            ll a = mx.get(j+1, n+1);
            ll b = mx.get(j, j+1);
            if(a+ D[p-i-1][j] > b){
                mx.set(j, a + D[p-i-1][j]);
            }
        }
    }
    cout << mx.get(0, n+1) << endl;;
}