#include <bits/stdc++.h>
using namespace std;

int main(){
    int dp[50][50];
    // llenar una lista para DP
    memset(dp,-1, sizeof(dp));

    for(int i=0; i<50;i++){
        for(int j=0; j<50;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}

