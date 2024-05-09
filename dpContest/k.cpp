#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int N, K;
int A[101];
int dp[(int)1e5+1];

int ganar(int monedas){
    if (dp[monedas] != -1) return dp[monedas];

    bool value = false;
    for (int i = 0; i < N; i++){
        if (monedas-A[i] > 0){
            int g = ganar(monedas-A[i]);
            value = value || !g;
        }
    }
    dp[monedas] = value;
    return value;
}

int main(){
    //freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for (int i = 0; i <= K; i++){
        dp[i] = -1;
    }

    for (int i = 0; i < N; i++){
        cin >> A[i];
        dp[A[i]] = 1;
    }

    for (int i = 0; i < A[0]; i++){
        dp[i] = 0;
    }


    bool res = ganar(K);
    if (res){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return 0;
}