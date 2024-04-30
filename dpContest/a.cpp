#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int cost(int n, int *a, int i) {
    if (dp[i] != -1) return dp[i];
    if (i == n-1){
        dp[i] = 0;
        return dp[i];
    }
    if (i == n-2){ 
        dp[i] = abs(a[i]-a[i+1]);
        return dp[i];
    }
    
    dp[i] = min(cost(n,a,i+1) + abs(a[i]-a[i+1]), cost(n,a,i+2) + abs(a[i]-a[i+2]));
    return dp[i];
}

int main(){

    int n;
    int a[10000];
    freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    dp.assign(n, -1);

    cout << cost(n,a,0) << endl;
    return 0;
}