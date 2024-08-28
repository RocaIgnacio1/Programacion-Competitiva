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


array<int, 4*4*100000> t;
vector<int> a;
void buildST(int v, int tl, int tr) { // este te hace las sumas
   if (tl == tr) {
       t[v] = a[tl];
   } else {
       int tm = (tl + tr) / 2;
       buildST(v * 2, tl, tm);
       buildST(v * 2 + 1, tm + 1, tr);
       t[v] = min(t[v * 2],t[v * 2 + 1]); //aca esta la parte en que las suma
   }
}

int queryST(int v, int tl, int tr, int l, int r){
   if( l > r){
       return 1e9+2;
   }
   if( l == tl && r == tr){
       return t[v];
   }
   int tm = (tl + tr)/2;
   int m = min(queryST(v*2, tl, tm, l, min(r, tm)), queryST(v*2+1, tm+1, tr, max(l, tm+1), r)); // esto lo hace para sumar
   //cout << l << " " << r << " " << m << endl;
   return m;

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
       t[v] = min(t[v*2], t[v*2+1]);
   }
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> v;
    forn(i, n){
        int p;
        cin >> p;
        a.push_back(p);
    }
    int mult = 1;
    while(mult < n) mult*=2;
    fora(n, i, mult){
        a.push_back(1e9+2);
    }
    /* forall(it, v){
        cout << *it << endl;
    } */
    int con = 0;
    buildST(1, 0, mult-1);
    forn(i, q){
        int p,l,r;
        cin >> p >> l >> r;
        if(p == 2)cout << queryST(1, 0, mult-1, l-1, r-1) << endl;
        if(p == 1) updateST(1, 0, mult-1, l-1, r);
    }
    return 0;
}