#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
using namespace std;

double dp[3001][3001];
int N;
double P[3000];
int maximo;

void probabilidad(int i){
    if(i==N) return;
    if(i==0){
        dp[0][1] = P[0];
        dp[0][0] = (1-P[0]);
    }else{

        for(int j=0; j<(i+2); j++){

            if(j==0){
                dp[i][j] = dp[i-1][0]* (1-P[i]);
            }else{
                if(j==i+1){
                dp[i][j] = dp[i-1][i]*P[i];
                } else{

                dp[i][j] = dp[i-1][j]*(1-P[i]) + dp[i-1][j-1]*(P[i]);   
   
                }


            }

            
        }
    }

    probabilidad(i+1);
}
 
int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    memset(dp,-1, sizeof(dp));
    for(int i=0; i<N; i++){
        cin >> P[i];
    }
    maximo = N/2 + 1;
    
    probabilidad(0);
    
    
    double respuesta=0.0;
    for(int w=N; w>=maximo; w--){
        respuesta += dp[N-1][w];
    }

    cout.precision(9);
    cout << respuesta << endl;
    
    return 0; 
}