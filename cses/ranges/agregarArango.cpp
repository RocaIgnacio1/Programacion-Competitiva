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

vector<ll> dif;
void createDif(vector<ll> &v){
    dif.push_back(v[0]);
    forn(i, v.size()-1){
        dif.push_back(v[i+1]- v[i]);
    }
}

void updateDif(int l, int r, ll inc){
    dif[l] += inc;
    if(r<dif.size())dif[r+1] -= inc;
}

void finDif(){
    ll sum = 0;
    forn(i, dif.size()){
        sum += dif[i];
        dif[i] = sum;
    }
}