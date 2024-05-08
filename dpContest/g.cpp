#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

long int dp[(int)1e5+1];
vector<vector<int>> G((int)1e5);

int maximo(int i){
    if (dp[i] != 0) return dp[i]; 

    if (G[i].size() == 0){
        return 0;
    }

    int max_idx = 0;
    int max = -1;
    for (int j = 0; j < G[i].size(); j++){
        dp[G[i][j]] = maximo(G[i][j]);
        if (dp[G[i][j]] > max){
            max = dp[G[i][j]];
        }
    }
    dp[i] = max +1;
    return dp[i];
}

int main(){
    //freopen("input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    memset(dp, 0, sizeof(dp));
    

    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;

        G[x-1].push_back(y-1);
    }


    int max = -1;
    for (int i = 0; i < N; i++){
        int m = maximo(i);
        if (m > max){
            max = m;
        }
    }
    cout << max << endl;
}