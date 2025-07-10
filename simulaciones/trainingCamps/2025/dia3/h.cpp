#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

using namespace std;

const int MAXN=26;

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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<string> names(n);

    forn(i, n) cin >> names[i];

    forn(i, n-1){
        int l1 = names[i].size();
        int l2 = names[i+1].size();

        int k = 0;
        while(k < l1 && k < l2 && names[i][k] == names[i+1][k]){
            k++;
        }
        // cout << k << ' ' << l1 << ' ' << l2 << endl;

        if (k < l1 && k < l2) { // encontre uno distinto sin llegar al final
            G[names[i][k]-'a'].push_back(names[i+1][k]-'a');
        } else if (k < l1 && k == l2) { // names[i+1] is a prefix of names[i]
            cout << "Impossible\n";
            return 0;
        }
    }

    // cout << "=======" << endl;
    // forn(i, MAXN) {
    //     cout << (char)('a'+i) << ": ";
    //     for(auto adj : G[i]){
    //         cout << (char)('a'+adj) << ' ';
    //     }
    //     cout << endl;
    // }

    state.assign(MAXN, 0);

    bool cicle = false;
    forn(i, MAXN){
        if (state[i] == 0){
            cicle = dfs(i);
        }
        if (cicle) break;
    }

    if (cicle){
        cout << "Impossible\n";
        return 0;
    }

    reverse(order.begin(), order.end());
    for(int i : order){
        cout << (char)('a'+i);
    }
    cout << '\n';

    return 0;
}
