#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000

/* Solucion: 
 * Cada componente va a tener solo un ciclo
 * Cada nodo solamente va a otro nodo
 * Para cada componente
 *  Guardar los nodos en el orden que aparecen
 *  Guardar la posicion 'pos' donde empieza el ciclo 
 *  Si k <= pos  => ans = comp[k]
 *  Si k > pos   => ans = comp[comp.size() - pos % k + k]
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> adj(n);
    vector<int> cicle(n); // Posicion en la que arranca el ciclo
    vector<bool> visited(n, false);
    vector<int> comp(n); // Componente a la que pertecene cada nodo
    vector<int> pos(n); // Componente a la que pertecene cada nodo
    map<int, deque<int>> compList;

    forn(i, n){
        cin >> adj[i]; adj[i]--;
    }

    int c = 0;
    forn(i, n){
        int u = i;
        int index = 0;
        if(visited[i]) continue;
        while(1){
            if(visited[u]){
                c++;
                break;
            }

            visited[u] = true;
            pos[u] = index;
            if (visited[adj[u]]){
                compList[comp[adj[u]]].push_front(u);
                cicle[comp[adj[u]]] = pos[adj[u]];
                comp[u] = comp[adj[u]];
            }else{
                compList[c].push_back(u);
                comp[u] = c;
            }
            u = adj[u];
            index++;
        }
    }

    forn(i, c){
        cout << i << " cicle: " << cicle[i] << endl; 
        cout << "nodes: ";
        for(auto l : compList[i]){
            cout << l+1 << ' ';
        }
        cout << endl;
    }
 
    return 0;
}
