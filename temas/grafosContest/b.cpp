#include <bits/stdc++.h>
using namespace std;

int n, m, ax, ay, bx, by;
char mat[1010][1010];


struct Nodo {
    tuple<int, int> id;
    vector<Nodo*> hijos;
};

Nodo grafo[1010][1010];
vector<vector<char>> movimientos;

string reconstruirCamino() {
    string camino = "";
    int x = bx, y = by;
    while (!(x == ax && y == ay)) {
        char mov = movimientos[x][y];
        camino += mov;
        if (mov == 'U') x++;
        else if (mov == 'D') x--;
        else if (mov == 'L') y++;
        else if (mov == 'R') y--;
    
    }
    reverse(camino.begin(), camino.end());
    return camino;
}

string camino(Nodo& nodoA){
    vector<vector<bool>> visitado(n, vector<bool>(m, false));
    queue<Nodo> cola;
    visitado[ax][ay] = true;
    cola.push(nodoA);

    
    while(!cola.empty()){
        Nodo actual = cola.front();
        cola.pop();
        int xActual = get<0>(actual.id);
        int yActual = get<1>(actual.id);
        if (xActual == bx && yActual == by) break;

        for (Nodo* vecino : grafo[xActual][yActual].hijos) {
            
            int xVecino = get<0>(vecino->id);
            int yVecino = get<1>(vecino->id);

            if (!visitado[xVecino][yVecino]) {
                visitado[xVecino][yVecino] = true;
                cola.push(*vecino);
                
                if(xActual==xVecino+1) movimientos[xVecino][yVecino] = 'U';
                if(xActual==xVecino-1) movimientos[xVecino][yVecino] = 'D';
                if(yActual==yVecino+1) movimientos[xVecino][yVecino] = 'L';
                if(yActual==yVecino-1) movimientos[xVecino][yVecino] = 'R';
            }
        }
    }
    if (!visitado[bx][by]) return ""; 
    return reconstruirCamino();
}

int main() {

    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    movimientos.resize(n, vector<char>(m, ' '));
    
    // lee y crea todos los nodos.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];

            if (mat[i][j] == '.' || mat[i][j] == 'A' || mat[i][j] == 'B') {
                //guardar las coordenadas de A y setearlo como un '.'
                if (mat[i][j] == 'A') ax = i, ay = j, mat[i][j] = '.';
                //guardar las coordenadas de B y setearlo como un '.'
                if (mat[i][j] == 'B') bx = i, by = j, mat[i][j] = '.';
                grafo[i][j].id = make_tuple(i, j);
            }
        }
    }
    
    // agrega el puntero a su vecino a su lista
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

    string ans = camino(grafo[ax][ay]);
    if(ans.length()==0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    

    return 0;
}
