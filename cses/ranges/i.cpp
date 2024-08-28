#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
#else
#endif


array<ll, 4*4*100000> t;
vector<int> h, aux;

void buildST(int v, int tl, int tr) { // este te hace las sumas
   if (tl == tr) {
       t[v] = aux[tl];
   } else {
       int tm = (tl + tr) / 2;
       buildST(v * 2, tl, tm);
       buildST(v * 2 + 1, tm + 1, tr);
       t[v] = t[v * 2] + t[v * 2 + 1]; //aca esta la parte en que las suma
   }
}

ll searchST(int v, int tl, int tr,  int m){ //buscar el primer elemento mayor a uno
    if( tl == tr){
       return tl;
    }
    int tm = (tl + tr)/2;
    if(t[2*v] >= m) return searchST(2*v, tl, tm, m);
    return searchST(2*v+1, tm+1, tr, m-t[2*v]);

}

void updateST(int v, int tl, int tr, int pos, int new_val){
   if(tl == tr){
       t[v] = new_val;
   } else {
       int tm = (tl + tr) / 2;
       if(pos <= tm){
           updateST(v*2, tl, tm, pos, new_val);
       }else{
           updateST(v*2 + 1, tm+1, tr, pos, new_val);
       }
       t[v] = t[v*2]+t[v*2+1];
   }
}
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n;
    vector<int> r;
    forn(i, n){
        int p;
        cin >> p;
        h.push_back(p);
        aux.push_back(1);
    }
    int mult = 1;
    while(mult < n) mult*=2;
    fora(n, i, mult){
        aux.push_back(0);
    }
    buildST(1, 0, mult-1);
    forn(i, n){
        int p;
        cin >> p;
        int pos = searchST(1, 0, mult-1, p);
        if(pos < n){
            updateST(1, 0, mult-1, pos, 0);
            cout << h[pos] << " ";
        }else{
            cout << 0 << endl;
        }
    }


}