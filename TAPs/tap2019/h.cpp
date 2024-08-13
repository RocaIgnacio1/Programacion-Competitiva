#include <bits/stdc++.h>
using namespace std;

#define BASE 31        
#define MOD 1000000007 


size_t customHash(const std::string& s) {
    size_t hashValue = 0;
    size_t basePower = 1; 
    for (char c : s) {
        hashValue = (hashValue + (c * basePower) % MOD) % MOD;
        basePower = (basePower * BASE) % MOD; 
    }
    return hashValue;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<size_t, int> hashTable;

    string s;
    string dict = "abcdefghijklmopqrstuvwxyz,._";

    int N, M, R;
    cin >> N;
    cin >> s;
    cin >> R >> M;
    
    for (int i = 0; i < R; ++i) {
        string T;
        cin >> T;
        size_t originalHash = customHash(T);
        hashTable[originalHash]++;
        
        
        for (int j = 0; j < M; ++j) {
            char originalChar = T[j];
            for (char c : dict) {
                if (c == originalChar) continue;

                T[j] = c;
                hashTable[customHash(T)]++;
            }
            T[j] = originalChar; 
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i <= N - M; ++i) {
        string substring = s.substr(i, M);
        size_t hashValue = customHash(substring);
    
        if (hashTable.find(hashValue) != hashTable.end()) {
            ans += hashTable[hashValue];
        }
    }
    cout << ans << endl;

    return 0;
}
