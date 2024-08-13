#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int dp[1002][1002][4];
bool visitado[1002][1002][4];
pair<int, int> C, E;
int N, M;

int recorrer(int n, int m, int p){
    cout << n << " " << m << " " << p << endl;
    if(dp[n][m][p] != -1) return dp[n][m][p];
    if(n == E.first && m == E.second && p == 2) return 0;
    visitado[n][m][p] = true;
    int mini = 1e9+100;
    if(p == 0){
        if(n+1<N) if(!visitado[n+1][m][0])  mini = min(mini, recorrer(n+1, m, 0)); //desde arriba
        if(m+1<M) if(!visitado[n][m+1][2]) mini = min(mini, recorrer(n, m+1, 2)); //desde la derecha
        if(m-2>=0) if(!visitado[n][m-2][2]) mini = min(mini, recorrer(n, m-2, 2)); //desde la izquierda
        if(n-1>=0) if(!visitado[n-1][m][0]) mini = min(mini, recorrer(n-1, m, 0)); //desde abajo
    }
    if(p == 1){
        if(n+2<N) if(!visitado[n+2][m][2]) mini = min(mini, recorrer(n+2, m, 2)); //desde arriba
        if(m+1<M) if(!visitado[n][m+1][1]) mini = min(mini, recorrer(n, m+1, 1)); //desde la derecha
        if(m-1>=0) if(!visitado[n][m-1][1]) mini = min(mini, recorrer(n, m-1, 1)); //desde la izquierda
        if(n-2>=0) if(!visitado[n-2][m][2]) mini = min(mini, recorrer(n-1, m, 2)); //desde abajo
    }
    if(p == 2){
        if(n+1<N) if(!visitado[n+1][m][1]) mini = min(mini, recorrer(n+1, m, 1)); //desde arriba
        if(m+2<M) if(!visitado[n][m+2][0]) mini = min(mini, recorrer(n, m+2, 0)); //desde la derecha
        if(m-1>=0) if(!visitado[n][m-1][0]) mini = min(mini, recorrer(n, m-1, 0)); //desde la izquierda
        if(n-2>=0) if(!visitado[n-2][m][1]) mini = min(mini, recorrer(n-2, m, 1)); //desde abajo
    }
    dp[n][m][p] = mini + 1;
    return mini + 1;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> N >> M;
    forn(i, N){
        forn(j, M){
            visitado[i][j][0] = false;
            visitado[i][j][1] = false;
            visitado[i][j][2] = false;
        }}
    forn(i, N){
        forn(j, M){
            char p;
            cin >> p;
            if(p == '#'){
                visitado[i][j][0] = true;
                visitado[i][j][1] = true;
                visitado[i][j][2] = true;
                if(j+1 < M) visitado[i][j+1][0] = true;
                if(i-1 > 0) visitado[i-1][j][1] = true;
            }
            if(p == '.'){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
                dp[i][j][2] = -1;
            }
            if(p == 'E'){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
                dp[i][j][2] = -1;
                E = make_pair(i, j);

            }
            if(p == 'C'){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
                dp[i][j][2] = -1;
                C = make_pair(i, j);
            }
            if(i == N-1){
                visitado[i][j][1] = true;
            }
            if(j == 0){
                visitado[i][j][0] = true;
            }
        }
    }
    forn(i, N){
        forn(j, M){
            cout << i << " " << j << ": " << visitado[i][j][0] << " " << visitado[i][j][1] << " " << visitado[i][j][2] << endl;
        }
    }
    int res = recorrer(C.first, C.second, 2);
    forn(i, N){
        forn(j, M){
            cout << i << " " << j << ": " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << endl;
        }
    }
    if( dp[C.first][C.second][2] > 1e9-1){
        cout << -1 << endl;
    }else{
        cout << dp[C.first][C.second][2] << endl;
    }
}