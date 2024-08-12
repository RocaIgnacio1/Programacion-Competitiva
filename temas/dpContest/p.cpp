#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

vector<int> G[(int)10e5+1];
long long int dp[(int)10e5+1][2];

long long int caminos(int nodo, int pintado, int anterior){
    if (dp[nodo][pintado] != -1) return dp[nodo][pintado];

    int p = 1;
    for (int i = 0; i < G[nodo].size(); i++){
        if (G[nodo][i] == anterior){
           continue; 
        }
        if (pintado == 0){
            p = ((p % MOD) * (caminos(G[nodo][i], 1, nodo) % MOD + caminos(G[nodo][i], 0, nodo) % MOD) % MOD) % MOD;
        }else{
            p = ((p % MOD) * (caminos(G[nodo][i], 0, nodo) % MOD)) % MOD;
        }
    }
    dp[nodo][pintado] = p;
    return p;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N-1; i++){
        int x, y;
        cin >> x >> y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    int raiz;
    for (int i = 1; i <= N; i++){
        if (G[i].size() == 1){
           dp[i][1] = 1; 
           dp[i][0] = 1; 
        }else{
            raiz = i;
        }
    }

    cout << (caminos(raiz, 1, -1) % MOD + caminos(raiz, 0, -1) % MOD) % MOD << endl;
}