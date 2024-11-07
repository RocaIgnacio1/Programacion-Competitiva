#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

/* Solucion: 
 * Union find guardando el size de cada componente
 * Cuando hacemos join, quedarnos con la componente mas grande hasta el momento
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
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
    int n, m;
    cin >> n >> m;

    UnionFind uf;
    uf.init(n);

    int components = n;
    forn(i, m){
        int a, b;
        cin >> a >> b; a--; b--;

        if (uf.comp(a) != uf.comp(b)){
            components--;
            uf.join(a, b);
        }
        cout << components << ' ' << uf.largest << endl;
    }

    return 0;
}
