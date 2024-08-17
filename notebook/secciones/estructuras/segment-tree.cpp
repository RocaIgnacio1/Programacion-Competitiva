#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int n, t[4*10000];

void buildST(int a[], int v, int tl, int tr) { // este te hace las sumas
   if (tl == tr) {
       t[v] = a[tl];
   } else {
       int tm = (tl + tr) / 2;
       buildST(a, v * 2, tl, tm);
       buildST(a, v * 2 + 1, tm + 1, tr);
       t[v] = t[v * 2] + t[v * 2 + 1]; //aca esta la parte en que las suma
   }
}

int queryST(int v, int tl, int tr, int l, int r){
   if( l > r){
       return 0;
   }
   if( l == tl && r == tr){
       return t[v];
   }
   int tm = (tl + tr)/2;
   return queryST(v*2, tl, tm, l, min(r, tm)) +
   + queryST(v*2+1, tm+1, tr, max(l, tm+1), r); // esto lo hace para sumar

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
       t[v] = t[v*2] + t[v*2+1];
   }
}
