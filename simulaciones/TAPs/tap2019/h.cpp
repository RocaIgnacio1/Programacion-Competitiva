#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

const ll BASE = 1777771;
const ll MOD = 999727999; 

const ll BASE2 = 1777771;
const ll MOD2 = 1070777777; 

ll customHash(ll mod, vector<ll> &pows, const std::string& s) {
    ll value = 0;
    ll power = s.size() - 1; 

    for (char c : s) {
        value = (value + (c * pows[power] % mod) % mod) % mod;
        power--;
    }
    return value;
}

ll rollingHash(ll base, ll mod, vector<ll> &pows, ll value, int n, char prev, char next){
    value = (value - prev * pows[n-1] % mod + mod) % mod;
    value = (value * base % mod) % mod;
    value = (value + next) % mod;

    return value;
}

ll rollingHashAt(ll mod, vector<ll> &pows, ll value, int pos, int n, char prev, char next) {
    value = (value - prev * pows[n-pos-1] % mod + mod) % mod;
    value = (value + next * pows[n-pos-1] % mod) % mod;

    return value;
}

int main(){
    //freopen("input.txt","r",stdin);
    freopen("h08_1.txt","r",stdin);
    //freopen("inputC.txt","r",stdin);
    unordered_map<ll, int> hashTable, hashTable2;
    string s;
    string dict = "abcdefghijklmnopqrstuvwxyz,._";

    int N, M, R;
    cin >> N;
    cin >> s;
    cin >> R >> M;

    vector<ll> pows1(N), pows2(N);
    pows1[0] = pows2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pows1[i] = (pows1[i-1] * BASE) % MOD;
        pows2[i] = (pows2[i-1] * BASE2) % MOD2;
    }
    for (int i = 0; i < R; ++i) {
        string T;
        cin >> T;
        ll originalHash = customHash(MOD, pows1, T);
        ll originalHash2 = customHash(MOD2, pows2, T);
        hashTable[originalHash]++;
        hashTable2[originalHash2]++;
        
        for (int j = 0; j < M; ++j) {
            for (char c : dict) {
                if (c == T[j]) continue;
                ll hash = rollingHashAt(MOD, pows1, originalHash, j, M, T[j], c);
                ll hash2 = rollingHashAt(MOD2, pows2, originalHash2, j, M, T[j], c);
                hashTable[hash]++;
                hashTable2[hash2]++;

            }
        }
    }
    
    int ans=0, ans2=0;
    ll hashValue = customHash(MOD, pows1, s.substr(0, M));
    ll hashValue2 = customHash(MOD2, pows2, s.substr(0, M));

    if (hashTable.find(hashValue)!=hashTable.end() && hashTable2.find(hashValue2)!=hashTable2.end() && hashTable[hashValue]==hashTable2[hashValue2]){
        ans += hashTable[hashValue];
        ans2 += hashTable2[hashValue2];
    }

    for (int i = 0; i <= N - M; ++i) {
        hashValue = rollingHash(BASE, MOD, pows1, hashValue, M, s[i], s[M+i]);

        hashValue2 = rollingHash(BASE2, MOD2, pows2, hashValue2, M, s[i], s[M+i]);

        if (hashTable.find(hashValue)!=hashTable.end() && hashTable2.find(hashValue2)!=hashTable2.end() && hashTable[hashValue]==hashTable2[hashValue2]){
            ans += hashTable[hashValue];
            ans2 += hashTable2[hashValue2];
        }
    }
    cout << ans << endl;

}
