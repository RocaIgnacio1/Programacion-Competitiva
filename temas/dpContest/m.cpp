#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
ll dp[101][100002];

void cargarDp(vector<int> v){
    dp[0][0] = 0;
    ll aux;
    //cout << "v[0]: " << v[0] << endl;
    for(int j = 0; j <= k; j++){
        if(j<=v[0]){
            dp[0][j] = j + 1;
        }else{
            dp[0][j] = dp[0][j-1];
        }
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j>v[i]){
                aux = v[i]; 
            }else{
                aux = j;
            }
            dp[i][j] = (dp[i-1][j] - dp[i-1][j-aux-1] + dp[i][j-1] + 1000000007)% 1000000007;
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        v.push_back(j);
    }
    cargarDp(v);
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << (dp[n-1][k] - dp[n-1][k - 1] + 1000000007) % 1000000007;

}
