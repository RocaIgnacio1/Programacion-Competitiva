#include <bits/stdc++.h>

using namespace std;

struct Nodo{
    int x;
    int y;
    bool monster;
    bool camino;
    vector<Nodo*> adj;
};

Nodo G[1001][1001];
vector<vector<char>> movimientos;
int xInicial, yInicial, xFinal, yFinal;

string reconstruirCamino() {
    string camino = "";
    int x = xFinal, y = yFinal;
    while (!(x == xInicial && y == yInicial)) {
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

int main(){
    freopen("input.txt", "r", stdin);

    queue<Nodo*> q;
    Nodo* start;

    int n, m;
    cin >> n >> m;
    movimientos.resize(n, vector<char>(m, ' '));

    char mat[1001][1001]; 
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char a;
            cin >> a;
            mat[i][j] = a;

            if (mat[i][j] != '#'){
                G[i][j] = Nodo{
                    .x=i,
                    .y=j,
                    .monster = (a == 'M'),
                    .camino = (a == 'A')
                };
            }
            if (a == 'A'){
                start = &G[i][j];
                xInicial=i;
                yInicial=j;
            }

        }
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] != '#'){
                for (int dir = 0; dir < 4; dir++){
                    int idx_x = i + directions[dir][0];
                    int idx_y = j + directions[dir][1];
                    if (idx_x >= 0 && idx_x < n && idx_y >= 0 && idx_y < m && mat[idx_x][idx_y] != '#') {
                        G[i][j].adj.push_back(&G[idx_x][idx_y]);
                    }
                }
            }
        }
    }
    //Ponemos todos los monstruos en cola
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (G[i][j].monster){
                q.push(&G[i][j]);
            }
        }
    }
    q.push(start);
    bool flag=false;
    
    while(!q.empty()){
        Nodo* i = q.front(); q.pop();

        int xActual = i->x;
        int yActual = i->y;

        if(i->camino && (xActual == 0 || xActual == n-1 || yActual == 0 || yActual == m-1)){
            xFinal = xActual;
            yFinal = yActual;
            flag=true;
            break; 
        }

        for(auto u: i->adj){
            int xVecino = u->x;
            int yVecino = u->y;

            if(!u->camino && !u->monster){
                q.push(u);
            }
            

            // si i es Camino y u no es ni Mounstro ni Camino, entonces u se convierte en Camino.
            if(i->camino && !u->monster && !u->camino){
                u->camino = true;
                //q.push(u);
                if (xActual == xVecino + 1) movimientos[xVecino][yVecino] = 'U';
                else if (xActual == xVecino - 1) movimientos[xVecino][yVecino] = 'D';
                else if (yActual == yVecino + 1) movimientos[xVecino][yVecino] = 'L';
                else if (yActual == yVecino - 1) movimientos[xVecino][yVecino] = 'R';
            }
            // si i es Mounstro y u es Camino, entonces u se convierte en Mounstro.
            if(i->monster){
                u->monster = true;
                
            }
            
        }    

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (G[i][j].monster){
                    cout << 'M';
                } else if (G[i][j].camino){
                    cout << 'A';
                } else if (mat[i][j] == '#'){
                    cout << '#';
                } else {
                    cout << '.';
                }
            }
            cout << endl;
        }   
        cout << endl;    
    }
    
    
    if(flag){
        cout << "YES" << endl;
        string ans = reconstruirCamino();
        cout << ans.length() << endl;
        cout << ans << endl;

    }else{
        cout << "NO" << endl;
    }

    return 0;
}