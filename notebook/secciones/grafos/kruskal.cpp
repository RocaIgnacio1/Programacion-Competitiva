#include <bits/stdc++.h>
#include "union_find.h"
using namespace std;

int n, m;
struct Ar{
    int a, b, w;
};
vector<Ar> E;
bool operator<(const Ar& a, const Ar &b){return a.w<b.w;}

int edges_used = 0;
int kruskal(){
    int cost=0;
    sort(E.begin(), E.end()); //Ordenar aristas de menor a mayor
    uf.init(n);
    for(Ar it : E){
        if(uf.comp(it.a) != uf.comp(it.b)){ //Si no estan conectados
            uf.join(it.a, it.b); //Conectar
            cost += it.w;
            edges_used++;
        }
    }
    return cost;
}
