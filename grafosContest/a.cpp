#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[1000][1000];
bool used[1000][1000];  

struct Nodo {
    tuple<int, int> id;
    vector<Nodo*> hijos;
};

Nodo grafo[1000][1000];

void componentesConexas(Nodo& nodo) {
    if (!used[get<0>(nodo.id)] [get<1>(nodo.id)]) {
        used[get<0>(nodo.id)] [get<1>(nodo.id)] = true;
        for (int i = 0; i < nodo.hijos.size(); i++) {
            componentesConexas(*(nodo.hijos[i]));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    int indice = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];

            if(mat[i][j] == '.'){
                grafo[i][j].id = make_tuple(i,j);
                indice++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                if (j > 0 && mat[i][j - 1] == '.') {
                    grafo[i][j].hijos.push_back(&grafo[i][j - 1]); 
                }
                if (j < m - 1 && mat[i][j + 1] == '.') {
                    grafo[i][j].hijos.push_back(&grafo[i][j + 1]); 
                }
                if (i > 0 && mat[i - 1][j] == '.') {
                    grafo[i][j].hijos.push_back(&grafo[i - 1][j]); 
                }
                if (i < n - 1 && mat[i + 1][j] == '.') {
                    grafo[i][j].hijos.push_back(&grafo[i + 1][j]); 
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            used[i][j] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' && !used[i][j]) {
                componentesConexas(grafo[i][j]);
                ans++;
            }
        }
    }
 
    cout << ans << endl;

    return 0;
}
