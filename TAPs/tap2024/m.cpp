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


array<pair<ll, ll>, 4*4*100000> t; //segment <sum, maximo> utilizando diff array
vector<ll> a;

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b){
	return (a.second < b.second);
}

void buildST(int v, int tl, int tr) { 
   if (tl == tr) {
       t[v] = make_pair(a[tl], a[tl]);
   } else {
       int tm = (tl + tr) / 2;
       buildST(v * 2, tl, tm);
       buildST(v * 2 + 1, tm + 1, tr);
       ll sum = t[v * 2].first + t[v * 2 + 1].first;
       t[v] = make_pair(sum, max(t[v * 2].second, t[v * 2].first + t[v * 2 + 1].second)); 
   }
}

void updateST(int v, int tl, int tr, int pos, ll new_val){
   if(tl == tr){
       t[v] = make_pair(t[v].first + new_val, t[v].first + new_val);
   } else {
       int tm = (tl + tr) / 2;
       if(pos <= tm){
           updateST(v*2, tl, tm, pos, new_val);
       }else{
           updateST(v*2 + 1, tm+1, tr, pos, new_val);
       }
       ll sum = t[v * 2].first + t[v * 2 + 1].first;
       t[v] = make_pair(sum, max(t[v * 2].second, t[v * 2].first + t[v * 2 + 1].second)); 
   }
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ll n, k;
    cin >> n >> k;
    ll K = k;
    ll acum = 0;
    vector<ll> v, p;
    vector<pair<ll, ll>> aux;
    vector<ll> resp;
    forn(i, n){
        ll f;
        cin >> f;
        v.push_back(f);
    }
    forn(i, n){
        ll f;
        cin >> f;
        aux.push_back(make_pair(i, f)); //guardo un array con la posicion y la cantidad de globos gratis que podes vender
    }
    sort(aux.begin(), aux.end(), sortbysec); 
    reverse(aux.begin(), aux.end()); //lo ordeno de mayor a menor con orden de la cantidad de globos gratis que podes vender

    for(auto i: aux){
        cout << i.first << " " << i.second << endl;
    }

    forn(i, n){
        ll f;
        cin >> f;
        acum += f;
        v[i] -= acum;
        p.push_back(f);
    }
    
    ll mult = 1;
    while(mult < n) mult*=2;
    fora(n, i, mult){
          v.push_back(-acum);
    }
    a.push_back(v[0]);
    fora(1, i, mult){
        a.push_back(v[i] - v[i-1]);
    }

    buildST(1, 0, mult-1);
    
    if(aux[0].second < K){
        resp.push_back((k - aux[0].second) * t[1].second);
        k = aux[0].second;
    }
    forn(i, aux.size() - 1){
        updateST(1, 0, mult-1, aux[i].first, p[aux[i].first]);
        if(aux[i].second != aux[i+1].second && aux[i].second < K){
            resp.push_back(((k - aux[i+1].second)) * t[1].second);
            k = aux[i+1].second;
        }
    }
    updateST(1, 0, mult-1, aux[aux.size() - 1].first, p[aux[aux.size() - 1].first]);
    resp.push_back(k * t[1].second);
    reverse(resp.begin(), resp.end());


    ll maxi = 0;
    acum = 0;
    for(auto i : resp){
        acum += i;
        maxi = max(acum, maxi);
    }
    cout << maxi << endl;
}