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


#define MAXN 200000
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


vector<int> pesos;
vector<vector<int>> sumProf;
vector<vector<int>> adj;
bool visitado[100005];
bool visited[100005];
vector<int> arbolAplanado, niveles, valores;

void dfs(int n, int nivel){
    if(visitado[n]) return;
    visitado[n] = true;
    //cout << n << " " << nivel << endl;
    if(nivel > sumProf.size()) sumProf.push_back({0, -1, 0});
    //cout << sumProf.size() << endl;
    if(pesos[n-1] > 0){
        //cout << "hola " << n << endl;
        vector<int> aux(3);
        //cout << aux[0] << endl;
        aux[0] = sumProf[nivel-1][0] + pesos[n-1];
        if(sumProf[nivel-1][1]!=-1){
            pair<int, int> minimo = mn.get(arbolAplanado[sumProf[nivel-1][1]], arbolAplanado[n]+1);
            //cout << "--" << n << " " << nivel << endl;
            //cout << "|" << minimo.first << " " << minimo.second << endl;
            aux[1] = minimo.second;
            aux[2] = nivel - minimo.first;
        }else{
            aux[1] = n;
            aux[2] = 0;
        }
        sumProf[nivel-1] = aux;
        //cout << sumProf[nivel-1][0] << " " << sumProf[nivel-1][1] << " " << sumProf[nivel-1][2] << endl;
    }
    forn(i, adj[n].size()){
        dfs(adj[n][i], nivel+1);
    }
    return;
}
void setSt(int n, int lvl){
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
        int k;
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
    vector<int> res = {0,0,0};
    forn(i, adj[0].size()){
        sumProf.clear();
        dfs(adj[0][i], 1);

        forn(j, sumProf.size()){
            if(sumProf[j][0] == res[0] && sumProf[j][2] < res[2]){
                res = sumProf[j];
            }
            if(sumProf[j][0] > res[0]){
                res = sumProf[j];
            }
            //cout << sumProf[j][0] << " " << sumProf[j][1] << " " << sumProf[j][2] << " " << endl;
        }
    }

    cout << res[0] << " " << res[2] + 1 << endl;

    return 0;
}