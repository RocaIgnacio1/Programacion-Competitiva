#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
using namespace std;

int N, K, turno;
ll A[3000];
ll dp[3000][3000];

ll juegoOptimo(int inicio, int fin)
{
    if (inicio > fin)
        return 0;

    if (dp[inicio][fin] != -1)
        return dp[inicio][fin];

    if ((fin - inicio + 1) % 2 == turno) 
        dp[inicio][fin] = max(A[inicio] + juegoOptimo(inicio + 1, fin), A[fin] + juegoOptimo(inicio, fin - 1));
    else 
        dp[inicio][fin] = min(-A[inicio] + juegoOptimo(inicio + 1, fin), -A[fin] + juegoOptimo(inicio, fin - 1));

    return dp[inicio][fin];
}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N;
    memset(dp,-1, sizeof(dp));
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    if(N%2==0) turno=0; 
    else turno=1;

    cout << juegoOptimo(0,N-1) << endl;

    return 0;
}