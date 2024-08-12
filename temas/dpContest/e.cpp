#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
ll W;
ll peso[101], valor[101];
ll dp[101][int(1e5)+1];

ll calcularPeso(int i, int valorRestante) {

    if(valorRestante == 0) return 0; 

    if(i<0) return 1e10; // no se puede llegar hasta el valor esperado con esta ramificacion de tomar/noTomar.

    if(dp[i][valorRestante] != -1) return dp[i][valorRestante];

    ll ans = calcularPeso(i-1, valorRestante);

    if(valorRestante - valor[i] >= 0){
        // se puede tomar
        ans = min( ans, calcularPeso(i-1, valorRestante - valor[i]) + peso[i]);
    }

    return dp[i][valorRestante] = ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    cin >> N >> W;
    for(int i=0; i<N; i++){
        cin >> peso[i];
        cin >> valor[i];
    }
    memset(dp, -1, sizeof(dp));
    
    int maximoValor = N*1000;

    for(int i=maximoValor; i>=0; i--){

        if(calcularPeso(N-1,i) <= W){
            // el valor i es posible con una mochila W.
            cout << i << endl;
            break;
        }

    }

    return 0;
}
