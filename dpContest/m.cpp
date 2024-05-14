#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
using namespace std;

int modulo = 1e9 + 7;
int N;
ll K;
ll A[101];
ll dp[101][100010];
ll acumulado[101];

ll formas(int i, ll caramelos)
{   
    //if(caramelos>acumulado[i]) return 0;

    if(i == N-1){
        if(caramelos > A[i]) return 0;
        else return 1;
    }
    if (dp[i][caramelos] != -1) return dp[i][caramelos];
    
    ll res=0;
    for(ll j=0; j<= min(A[i],caramelos) ; j++){
         
        res += (formas(i+1, caramelos-j)% modulo);
    }
    

    dp[i][caramelos] = (res%modulo);
    return dp[i][caramelos];

}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    memset(dp,-1, sizeof(dp));
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    ll sumador=0;
    for(int i=N-1; i>=0; i--){
        sumador += A[i];
        acumulado[i]=sumador;
    }

    cout << formas(0, K)%modulo << endl;

    return 0;
}
