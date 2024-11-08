#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
const int MAXN = 1e5;

/*  Topological Sort
 * */

vector<int> state; //Tres estados 0, 1, 2
                   //0 -> no visitado, 1 -> visitando, 2 -> totalmente visitado
vector<int> G[MAXN];
vector<int> order;

bool dfs(int nodo){ //Devolvemos si true si encontramos un ciclo
    if(state[nodo] == 2) return false;
    state[nodo] = 1;

    bool cicle = false;
    for(auto it : G[nodo]){
        if(state[it] == 0){ 
            cicle = dfs(it);
        }else if(state[it] == 1){
            return true;
        }
    }
    state[nodo] = 2;
    order.push_back(nodo);
    return cicle;
}

int main(){
    int n, m;
    // Leer grafo

    state.assign(n+1, 0);

    bool cicle = false;
    forn(i, n){
        if (state[i] == 0){
            cicle = dfs(i);
        }
        if (cicle) break;
    }

    if (cicle){
        cout << "IMPOSSIBLE\n";
    }else{
        reverse(order.begin(), order.end());
        for(int i : order){
            cout << i+1 << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}
