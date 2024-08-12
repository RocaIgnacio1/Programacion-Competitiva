#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<vector<ll>> dp;

ll precioMax (int n, int w, ll *peso, ll *valor, int i){
    if(dp[i][w] != -1) return dp[i][w];

    if(i == n-1){
        if(peso[i] > w) return 0;
        else return valor[i];
    }
    
    if( peso[i] > w){
        dp[i][w] = precioMax(n, w, peso, valor, i+1);
    }else{ 
        dp[i][w] = max( precioMax(n, w, peso, valor, i+1), precioMax(n, w-peso[i], peso, valor, i+1) + valor[i]);
        
    }
    return dp[i][w];
}



int main() {
    int n, w;
    //freopen("input.txt", "r", stdin);
    cin >> n >> w;

    ll peso[100], valor[100];
    for(int i=0; i<n; i++){
        cin >> peso[i];
        cin >> valor[i];
    }
    // vector bidimensional para guardar los maximos valores de cada subproblema parado en el articulo i con un peso actual de w
    dp.assign(n, vector<ll>(w + 1, -1));
    cout << precioMax(n, w, peso, valor, 0) << endl;

    return 0;
}
