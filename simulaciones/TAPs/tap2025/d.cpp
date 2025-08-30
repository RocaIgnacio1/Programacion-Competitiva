#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define dbg(v) cerr << #v << ": " << v;
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 300000
#define operacion(x, y) op(x, y)
#define neutro {-1, 0, 0}
#define tipo tuple<int, int, int> // {ganas o perdes, cacheTotal, acumx, acumy}

tipo op(tipo x, tipo y){
    auto [x1, x2, x3] = x;
    auto [y1, y2, y3] = y;
    if(x1==-1 && y1 == -1){
        return {-1, x2+y2, x3+y3};
    }
    if(x1 == -1){
        return {y1, x2+y2, x3+y3};
    }
    if(y1 == -1){
        if(!x1){
            return {x1, x2, x3+y3+y2};
        }else{
            return {x1, x2, x3+y3};
        }
    }

    if(!x1){
        return {y1, x2, x3+y3+y2};
    }else{
        return {y1, x2, x3+y3};
    }
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
}solve;

int main() {
    HOLA
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> empates;
    map<string, int> palabras;
    vector<string> nombre;
    vector<vector<pair<int, bool>>> pospal;
    solve.init(n+m+2);
    solve[0] = {0, 0, 0};
    forn(i, n+m){
        int v, w;
        string p, q;
        cin >> v >> p >> w >> q;
        if(!palabras.count(p)) palabras[p] = pospal.size(), pospal.push_back({}), nombre.push_back(p);
        if(!palabras.count(q)) palabras[q] = pospal.size(), pospal.push_back({}), nombre.push_back(q);
        if(p==q){
            if(v>w){
                empates.push_back({i+1, 0});
                solve[i+1] = {0, 0, 1};
            }else{
                empates.push_back({i+1, 1});
                solve[i+1] = {1, 0, 0};
            }
        }else{
            
            solve[i+1] = {-1,1,0};
            pospal[palabras[p]].push_back({i, 0});
            pospal[palabras[q]].push_back({i, 1});
        }
    }
    solve[n+m+1] = {0, 0, 0};
    solve.updall();
    forn(i, pospal.size()){
        for(auto j : pospal[i]){
            solve.set(j.first+1, {j.second, 0, !j.second});
        }
        auto [b,c,d] = solve.get(0, n+m+2);
        //cout << nombre[i] << " " << d << endl;
        if(d == n){
            cout << nombre[i] << endl;
            return 0;
        }
        for(auto j : pospal[i]){
            solve.set(j.first+1, {-1,1,0});
        }
    }

    cout << "*" << endl;


    return 0;
}