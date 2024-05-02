#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll peso[101], valor[101];
ll dp[101][100000];

ll precioMax(int n, int w, int i) {
    
    if (dp[i][w] != 0) return dp[i][w];
    if (w == 0) return 0;
    if (i >= n) return 0;
    if(i == n-1){
        if(peso[i] > w) return 0;
        else return valor[i];
    }
    
    if( peso[i] > w){
        dp[i][w] = precioMax(n, w, i+1);
    }else{ 
        dp[i][w] = max( precioMax(n, w, i+1), precioMax(n, w-peso[i], i+1) + valor[i]);
        
    }
    return dp[i][w];
}


int main() {
    ll n,w;
    freopen("input.txt", "r", stdin);
    cin >> n >> w;
    for(int i=0; i<n; i++){
        cin >> peso[i];
        cin >> valor[i];
    }
    memset(dp, -1, sizeof(dp));
    
    cout << precioMax(n, w, 0) << endl;

    return 0;
}




