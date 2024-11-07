#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;

/* Solucion: 
 * MST, Kruskall
 * llevar cuantas aristas agregamos al mst
 * si edges_used != n-1 => impossible
 * */

// Union find guardando el tamaño de los sets
struct UnionFind{
	vector<int> f;//the array contains the parent of each node
    vector<int> size;
    int largest;
	void init(int n){
        f.clear(); f.insert(f.begin(), n, -1); 
        largest = 1;
        size.insert(size.begin(), n, 1);
    }
	int comp(int x){return (f[x]==-1?x:f[x]=comp(f[x]));}//O(1)
    bool join(int i, int j) {
        int rootI = comp(i);
        int rootJ = comp(j);

        if (rootI == rootJ) return true; // Ya están en el mismo componente

        if (size[rootI] < size[rootJ]) {
            swap(rootI, rootJ);
        }

        f[rootJ] = rootI;
        size[rootI] += size[rootJ];
        largest = max(largest, size[rootI]); // Actualizar la componente más grande
        return false;
    }
    bool same(int a, int b) {
        return comp(a) == comp(b);
    }
} uf;

int n, m;
int edges_used = 0;

struct Ar{
    int a, b;
    ll w;
};
vector<Ar> E;
bool operator<(const Ar& a, const Ar &b){return a.w<b.w;}
ll kruskal(){
    ll cost=0;
    sort(E.begin(), E.end());//ordenar aristas de menor a mayor
    uf.init(n);
    for(Ar it : E){
        if(uf.comp(it.a) != uf.comp(it.b)){//si no estan conectados
            uf.join(it.a, it.b);//conectar
            cost += it.w;
            edges_used++;
        }
    }
    return cost;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
    cin >> n >> m;

    forn(i, m){
        int a, b;
        ll w;
        cin >> a >> b >> w; a--; b--;
        E.push_back(Ar{a, b, w});
    }

    ll ans = kruskal();
    if (edges_used == n-1){ //cuando es un arbol
        cout << ans << '\n';
    }else{
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
