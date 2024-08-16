#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define BASE 1777771
#define MOD 999727999

#define BASE2 1777771
#define MOD2 1070777777

typedef __int128 size_tt;

size_tt customHash(ll mod, vector<ll> &pows, const std::string& s) {
    size_tt value = 0;
    size_tt power = s.size() - 1; 

    for (char c : s) {
        value = (value + (c * pows[power] % mod) % mod) % mod;
        power--;
    }
    return value;
}

size_tt rollingHash(ll base, ll mod, vector<ll> &pows, size_tt value, int n, char prev, char next){
    value = (value - prev * pows[n-1] % mod + mod) % mod;
    value = (value * base % mod) % mod;
    value = (value + next) % mod;

    return value;
}

size_tt rollingHashAt(ll mod, vector<ll> &pows, size_tt value, int pos, int n, char prev, char next) {
    value = (value - prev * pows[n-pos-1] % mod + mod) % mod;
    value = (value + next * pows[n-pos-1] % mod) % mod;

    return value;
}

int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<size_tt, int> hashTable;
    unordered_map<size_tt, int> hashTable2;

    string s;
    string dict = "abcdefghijklmopqrstuvwxyz,._";

    int N, M, R;
    cin >> N;
    cin >> s;
    cin >> R >> M;

    vector<ll> pows1(M);
    pows1[0] = 1;
    forn(i, M-1){
        pows1[i+1] = (pows1[i] * BASE) % MOD;
    }

    vector<ll> pows2(M);
    pows2[0] = 1;
    forn(i, M-1){
        pows2[i+1] = (pows2[i] * BASE2) % MOD2;
    }
    
    for (int i = 0; i < R; ++i) {
        string T;
        cin >> T;
        size_tt originalHash = customHash(MOD, pows1, T);
        hashTable[originalHash]++;

        size_tt originalHash2 = customHash(MOD2, pows2, T);
        hashTable2[originalHash2]++;
        
        for (int j = 0; j < M; ++j) {
            for (char c : dict) {
                if (c == T[j]) continue;
                size_tt hash = rollingHashAt(MOD, pows1, originalHash, j, M, T[j], c);
                hashTable[hash]++;

                size_tt hash2 = rollingHashAt(MOD2, pows2, originalHash2, j, M, T[j], c);
                hashTable2[hash2]++;
            }
        }
    }
    
    int ans = 0;
    size_tt hashValue = customHash(MOD, pows1, s.substr(0, M));
    size_tt hashValue2 = customHash(MOD2, pows2, s.substr(0, M));

    if (hashTable[hashValue] > 0 && hashTable2[hashValue2] > 0 && hashTable[hashValue] == hashTable2[hashValue2]){
        ans += hashTable[hashValue];
    }

    for (int i = 0; i <= N - M; ++i) {
        hashValue = rollingHash(BASE, MOD, pows1, hashValue, M, s[i], s[M+i]);

        hashValue2 = rollingHash(BASE2, MOD2, pows2, hashValue2, M, s[i], s[M+i]);

        if (hashTable[hashValue] > 0 && hashTable2[hashValue2] > 0 && hashTable[hashValue] == hashTable2[hashValue2]){
            ans += hashTable[hashValue];
        }
    }
    cout << ans << endl;

    return 0;
}
