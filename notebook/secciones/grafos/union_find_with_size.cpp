#include <bits/stdc++.h>
using namespace std;

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

        if (rootI == rootJ) return true; // Ya estan en el mismo componente

        if (size[rootI] < size[rootJ]) {
            swap(rootI, rootJ);
        }

        f[rootJ] = rootI;
        size[rootI] += size[rootJ];
        largest = max(largest, size[rootI]); // Actualizar la componente mas grande
        return false;
    }
    bool same(int a, int b) {
        return comp(a) == comp(b);
    }
} uf;
