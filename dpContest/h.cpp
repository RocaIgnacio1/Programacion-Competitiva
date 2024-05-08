#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
using namespace std;

int modulo = 1e9 + 7;
ll dp[1010][1010];
int H, W;
char M[1010][1010];

int caminos(int i, int j){

    // llego al final. suma 1
    if(i==H-1 && j == W-1) return 1;

    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j]=0;
    if(i+1 < H && M[i+1][j]=='.') dp[i][j] += caminos(i+1, j) % modulo;
    if(j+1 < W && M[i][j+1]=='.') dp[i][j] += caminos(i, j+1) % modulo;

    return dp[i][j];
}
 
int main(){
    freopen("input.txt", "r", stdin);
    cin >> H >> W;
    memset(dp,-1, sizeof(dp));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> M[i][j];
        }
    }
    
    cout << caminos(0,0) % modulo << endl;
    
}