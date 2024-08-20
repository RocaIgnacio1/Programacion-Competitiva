#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
 
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
 
const ll BASE = 1009;
const ll MOD = 10000000000000003; 
vector<ll> pows(2000);
 
ll mul(ll a, ll b, ll m) { //hace (a*b)%m
	ll q = (ll)((long double)a*b/m);
	ll r = a*b-m*q;
	while(r<0) r += m;
	while(r>=m) r -= m;
	return r;
}
 
ll customHash(const std::string& s) {
    ll value = 0;
    ll power = s.size() - 1; 
 
    for (char c : s) {
        value = (value + mul(c, pows[power],MOD)) % MOD;
        power--;
    }
    return value;
}
 
ll rollingHash(ll value, int n, char prev, char next){
    value = (value - mul(prev, pows[n-1], MOD) + MOD) % MOD;
    value = (mul(value, BASE,  MOD)) % MOD;
    value = (value + next) % MOD;
 
    return value;
}
 
ll rollingHashAt(ll value, int pos, int n, char prev, char next) {
    value = (value - mul(prev, pows[n-pos-1], MOD) + MOD) % MOD;
    value = (value +mul(next, pows[n-pos-1], MOD)) % MOD;
 
    return value;
}
 
int main(){
    //freopen("inputC.txt","r",stdin);
    unordered_map<ll, int> hashTable;
    string s;
    string dict = "abcdefghijklmnopqrstuvwxyz,._";
 
    int N, M, R;
    cin >> N >> s >> R >> M;
 
    pows[0] = 1;
    for (int i = 1; i < M; ++i) {
        pows[i] = mul(pows[i-1] , BASE,MOD) % MOD;
    }
    for (int i = 0; i < R; ++i) {
        string T;
        cin >> T;
        ll originalHash = customHash(T);
        hashTable[originalHash]++;
        
        for (int j = 0; j < M; ++j) {
            for (char c : dict) {
                if (c == T[j]) continue;
                ll hash = rollingHashAt(originalHash, j, M, T[j], c);
                hashTable[hash]++;
            }
        }
    }
    
    int ans = 0;
    ll hashValue = customHash(s.substr(0, M));
 
    if (hashTable.find(hashValue) != hashTable.end()) {
        ans += hashTable[hashValue];
    }
 
    for (int i = 1; i <= N - M; ++i) {
        hashValue = rollingHash(hashValue, M, s[i-1], s[M+i-1]);
        if (hashTable.find(hashValue) != hashTable.end()) {
            ans += hashTable[hashValue];
        }
    }
    cout << ans << endl;
    return 0;
}