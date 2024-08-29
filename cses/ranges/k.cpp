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

array<ll, 4*2*100000> t;
vector<ll> a;
void buildST(int v, int tl, int tr) { // este te hace las sumas
   if (tl == tr) {
       t[v] = a[tl];
   } else {
       int tm = (tl + tr) / 2;
       buildST(v * 2, tl, tm);
       buildST(v * 2 + 1, tm + 1, tr);
       t[v] = max(t[v * 2],t[v * 2 + 1]); //aca esta la parte en que las suma
   }
}

int queryST(int v, int tl, int tr, int l, int r){
   if( l > r){
       return -1e9-5;
   }
   if( l == tl && r == tr){
       return t[v];
   }
   int tm = (tl + tr)/2;
   int m = max(queryST(v*2, tl, tm, l, min(r, tm)), queryST(v*2+1, tm+1, tr, max(l, tm+1), r)); // esto lo hace para sumar
   //cout << l << " " << r << " " << m << endl;
   return m;

}

void updateST(int v, int tl, int tr, int pos, ll new_val){
   if(tl == tr){
       t[v] = new_val;
   } else {
       int tm = (tl + tr) / 2;
       if(pos <= tm){
           updateST(v*2, tl, tm, pos, new_val);
       }else{
           updateST(v*2 + 1, tm+1, tr, pos, new_val);
       }
       t[v] = max(t[v*2], t[v*2+1]);
   }
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n, q;
    cin >> n >> q;
    ll sum = 0;
    forn(i,n){
        int p;
        cin >> p;
        sum += p;
        a.push_back(sum);
    }
    int mult = 1;
    while(mult < n) mult*=2;
    fora(n, i, mult){
        a.push_back(-1e9-5);
    }
    buildST(1, 0, mult-1);
    forn(i,q){
        int p, x, y;
        cin >> p >> x >> y;
        if(p==1){
            if(x>1)updateST(1, 0, mult-1, x-1, a[x-2] + y);
            else updateST(1, 0, mult-1, x-1, y);
        }else{
            int aux = queryST(1, 0, mult - 1, x-1, y-1);
            if(x>1) cout << aux << endl;
            else cout << aux<< endl;
        }
    }

}