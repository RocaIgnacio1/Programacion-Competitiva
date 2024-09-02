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

array<pair<ll, ll> , 4*2*100000> t;
vector<ll> a;
void buildST(int v, int tl, int tr) { // este te hace las sumas
   if (tl == tr) {
       t[v] = make_pair(a[tl], a[tl]);
   } else {
       int tm = (tl + tr) / 2;
       buildST(v * 2, tl, tm);
       buildST(v * 2 + 1, tm + 1, tr);
       ll prefix = t[v * 2].second + t[v * 2 + 1].second;
       t[v] = make_pair(max(t[v * 2].first, t[v * 2].second + t[v * 2 + 1].first), prefix); //aca esta la parte en que las suma
   }
}

pair<int,int> queryST(int v, int tl, int tr, int l, int r){
   if( l > r){
       return make_pair(0,0);
   }
   if( l == tl && r == tr){
       return t[v];
   }
   int tm = (tl + tr)/2;
   //cout << l << " " << r << " " << m << endl;
   pair<int,int> q1 = queryST(v*2, tl, tm, l, min(r, tm));
   pair<int,int> q2 = queryST(v*2+1, tm+1, tr, max(l, tm+1), r);// esto lo hace para sumar
   if(q1.first>q2.first) return q1;
   return q2;
}

void updateST(int v, int tl, int tr, int pos, ll new_val){
   if(tl == tr){
       t[v] = make_pair(new_val, new_val);
   } else {
       int tm = (tl + tr) / 2;
       if(pos <= tm){
           updateST(v*2, tl, tm, pos, new_val);
       }else{
           updateST(v*2 + 1, tm+1, tr, pos, new_val);
       }
       ll prefix = t[v * 2].second + t[v * 2 + 1].second;
       t[v] = make_pair(max(t[v * 2].first, t[v * 2].second + t[v * 2 + 1].first), prefix);
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
        a.push_back(p);
    }
    int mult = 1;
    while(mult < n) mult*=2;
    fora(n, i, mult){
        a.push_back(0);
    }
    buildST(1, 0, mult-1);
    forn(i,q){
        int p, x, y;
        cin >> p >> x >> y;
        if(p==1){
            updateST(1, 0, mult-1, x-1, y);
        }else{
            pair<int, int> aux = queryST(1, 0, mult - 1, x-1, y-1);
            cout << aux.first << endl;
        }
    }

}