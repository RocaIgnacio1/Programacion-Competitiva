#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000


bool ganador (vector<int> &tablero, int turno){
    vector<vector<int>> pos_ganadoras = { {1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
    int ban = true;
    for(auto i: pos_ganadoras){
        ban=true;
        for(auto j: i){
            if(tablero[j-1] != turno)ban=false;
        }
        if(ban)break;
    }

    return ban;
}
vector<set<int>> r(9);

int solve(vector<int> &tablero, int turno){
    
    int termino = ganador(tablero, turno^1);
    if(termino){
        return turno^1;
    }

    // se puede jugar?
    int jugar=0;

    int gana=0, empata=0;
    forn(i,9){
        // tiene que estar desocupado
        if(tablero[i]!=-1)continue;

        // tiene que estar habilitada su restriccion
        bool habilitada = true;
        for(auto j: r[i]){
            if(tablero[j]==-1)habilitada=false;
        }
        if(!habilitada)continue;
        jugar=1;
        tablero[i]=turno;
        char resultado_parcial = solve(tablero, turno^1);
        tablero[i]=-1;

        if(resultado_parcial==2)empata=1;
        if(resultado_parcial==turno){
            gana=1;
            break;
        }
    }

    if(!jugar)return 2;
    if(gana)return turno;
    if(empata)return 2;
    return turno^1;
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    forn(i,n){
        int a,b;
        cin >> a >> b;
        r[b-1].insert(a-1);
    }

    vector<int> tablero = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    int ans = solve(tablero,1);
    
    if(ans==1){
        cout << "X" << endl;
    }else{
        if(ans==2)cout << "E" << endl;
        else cout << "O" << endl;
    }

    return 0;
}