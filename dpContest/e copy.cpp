#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long peso[101], valor[101];
long long dp[101][100000];

ll precioMax(int i, int valLeft) {

    if(valLeft == 0) return 0;
    if(i<0) return 1e15;
    if(dp[i][valLeft] != -1) return dp[i][valLeft];
    ll ans = precioMax(i-1, valLeft);

    if(valLeft - valor[i] >= 0){
        ans = min(ans, precioMax(i-1, valLeft - valor[i]) + peso[i]);
    }

    return dp[i][valLeft] = ans;
    
}


int main() {
    ll n,w;
    //freopen("input.txt", "r", stdin);
    cin >> n >> w;

    for(int i=0; i<n; i++){
        cin >> peso[i];
        cin >> valor[i];
    }

    memset(dp, -1, sizeof(dp));

    for(int i=1e5; i>=0; i--){
        
        if( precioMax(n-1, i) <=w){
            cout << i << endl;
        break;
        }
     }

    return 0;
}



