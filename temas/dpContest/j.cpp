#include <bits/stdc++.h>

using namespace std;

int N;
double dp[301][301][301];

double expected(int i, int j, int k){
    if (dp[i][j][k] != 0) return dp[i][j][k];
    
    double c1 = 0, c2 = 0, c3 = 0;
    double n = (double)N/(i+j+k);
    
    if (i > 0){
        c1 = (expected(i-1, j, k) + n) * i;
    }
    if (j > 0){
        c2 = (expected(i+1, j-1, k) + n) * j;
    }
    if (k > 0){
        c3 = (expected(i, j+1, k-1) + n) * k;
    }

    dp[i][j][k] = (c1+c2+c3) / (i+j+k);
    return dp[i][j][k]; 
}

int main(){
    int cant[4];
    freopen("input.txt", "r", stdin);
    cin >> N;
    memset(cant, 0, sizeof(cant));

    for (int i = 0; i < N; i++){
        //int n;
        //cin >> n;
        cant[1]++;
    }

    dp[1][0][0] = N;
    dp[0][1][0] = 2*N;
    dp[0][0][1] = 3*N;
    
    cout << fixed << setprecision(20) << expected(cant[1], cant[2], cant[3]) << endl;
}