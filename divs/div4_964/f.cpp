#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Función para calcular nCk % MOD
long long binomial_coefficient(long long n, long long k, vector<long long>& fact, vector<long long>& inv_fact) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

// Función para precomputar factoriales e inversos modulares
void precompute_factorials(int max_n, vector<long long>& fact, vector<long long>& inv_fact) {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = inv_fact[i - 1] * binomial_coefficient(MOD, i, fact, inv_fact) % MOD;
    }
}

int main() {
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    
    int max_n = 200000;
    vector<long long> fact(max_n + 1), inv_fact(max_n + 1);
    precompute_factorials(max_n, fact, inv_fact);
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long sum = 0;
        int m = (k + 1) / 2;  // posición del mediano en la subsecuencia
        
        // Contribución de cada elemento como el mediano
        for (int i = 0; i <= n - k; i++) {
            int l = i + 1;  // número de elementos a la izquierda de 'i'
            int r = n - i;  // número de elementos a la derecha de 'i'
            
            long long contrib = binomial_coefficient(l - 1, m - 1, fact, inv_fact) * binomial_coefficient(r - 1, k - m, fact, inv_fact) % MOD;
            sum = (sum + contrib * a[i]) % MOD;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}



