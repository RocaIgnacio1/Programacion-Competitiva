#include <bits/stdc++.h>
using namespace std;

vector<int> dp;


int cost(int n, int *a, int i,int k) {
    if (dp[i] != -1) return dp[i];
    if (i == n-1){
        dp[i] = 0;
        return dp[i];
    }
    if (i == n-2){ 
        dp[i] = abs(a[i]-a[i+1]);
        return dp[i];
    }
    int minimo = INT_MAX;
    for(int j=i+1; j<(min(n,i+k+1)); j++){
        int costActual = abs(a[i] - a[j]);
        minimo = min(minimo, costActual + cost(n,a,j,k));
    }
    return dp[i] = minimo;
}

int main(){

    int n, k;
    int a[100000];
    
    //freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    dp.assign(n, -1);
    
    cout << cost(n,a,0,k) << endl;
    return 0;
}