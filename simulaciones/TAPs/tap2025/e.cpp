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


#define MAXN 600005
#define operacion(x, y) min(x, y)
#define neutro make_pair(1e9+10, -1)
#define tipo pair<int, int> 

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
}mn;

struct tres{
    ll uno;
    ll dos;
    ll tres;
};


vector<ll> pesos;
vector<vector<tres>> sumProf;
vector<vector<int>> adj;
bool visitado[200005];
bool visited[200005];
vector<int> arbolAplanado, niveles, valores;
tres res;

void dfs(int n, int nivel, int col){
    if(visitado[n]) return;
    visitado[n] = true;
    //cout << n << " " << nivel << endl;
    if(nivel > sumProf[col].size()) sumProf[col].push_back({0, -1, 0});
    //cout << sumProf.size() << endl;
    if(pesos[n-1] > 0){
        //cout << "hola " << n << endl;
        tres aux;
        //cout << aux.uno << endl;
        aux.uno = sumProf[col][nivel-1].uno + pesos[n-1];
        if(sumProf[col][nivel-1].dos!=-1){
            int a = min (arbolAplanado[sumProf[col][nivel-1].dos], arbolAplanado[n]);
            int b = max (arbolAplanado[sumProf[col][nivel-1].dos], arbolAplanado[n]);
            pair<int, int> minimo = mn.get(a,b+1);
            //cout << "--" << n << " " << nivel << endl;
            //cout << "|" << minimo.first << " " << minimo.second << endl;
            aux.dos = minimo.second;
            aux.tres = nivel - minimo.first;
        }else{
            aux.dos = n;
            aux.tres = 0;
        }
        sumProf[col][nivel-1] = aux;
        if(sumProf[col][nivel-1].uno == res.uno && sumProf[col][nivel-1].tres < res.tres){
                res = sumProf[col][nivel-1];
        }
        if(sumProf[col][nivel-1].uno > res.uno){
            res = sumProf[col][nivel-1];
        }
        //cout << sumProf[nivel-1].uno << " " << sumProf[nivel-1].dos << " " << sumProf[nivel-1].tres << endl;
    }
    forn(i, adj[n].size()){
        dfs(adj[n][i], nivel+1, col);
    }
    return;
}
void setSt(ll n, ll lvl){
    if(visited[n]) return;
    visited[n] = true;
    arbolAplanado[n] = niveles.size();
    niveles.push_back(lvl);
    valores.push_back(n);
    forn(i, adj[n].size()){
        setSt(adj[n][i], lvl+1);
        niveles.push_back(lvl);
        valores.push_back(n);
    }
    return;
}

int main() {
    HOLA
    int n;
    cin >> n;
    adj.assign(n, {});
    arbolAplanado.assign(n, -1);
    forn(i, n-1){
        ll k;
        cin >> k;
        pesos.push_back(k);
    }

    forn(i, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    setSt(0, 0);
    mn.init(niveles.size());
    forn(i, niveles.size()){
        mn[i] = make_pair(niveles[i], valores[i]);
    }
    mn.updall();
    visitado[0] = true;
    forn(i, adj[0].size()){
        sumProf.push_back({});
        dfs(adj[0][i], 1, i);
    }

    cout << res.uno << " " << res.tres + 1 << endl;

    return 0;
}