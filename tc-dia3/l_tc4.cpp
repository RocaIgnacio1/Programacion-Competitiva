#include <iostream>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>  
#include <vector>     
 
using namespace std;
using ll = long long;
 
const int M = 998244353;
const int N = 100005;
ll F[N], I[N]; 
 
ll nCr(ll n, ll r){
    if(n < 0 || r < 0 || n < r) return 0;
    return (F[n] * I[r] % M) * I [n - r] % M;
}
 
ll inv(ll a){
    int p = M - 2;
    ll ans = 1;
    while(p > 0){
        if(p & 1) ans = ans * a % M;
        a = a * a % M;
        p /= 2;
    }
    return ans;
}
 
void fact(){
    F[0] = 1;
    for(int i = 1; i < N; i++){
        F[i] = F[i - 1] * (i) % M;
    }
    I[N - 1] = inv(F[N - 1]);
    for(int i = N - 2; i >= 0; i--){
        // I[i] = I[i + 1] * inv(i + 1) % M;
        I[i] = inv(F[i]) % M;
    }
}
 
int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    fact();
    while(t--){
        int n;
        cin >> n;
        string s; cin >> s;
        // cout << s << endl;
        ll z = count(s.begin(), s.end(), 48);
        ll o = 0;
        bool ch = 0;
        for(int i = 0; i < s.size(); i++){
            if(ch == 1 && s[i] == '1') o++, ch = 0;
            else if(s[i] == '1') ch = 1;
            else ch = 0;
        }
        // cout << s << endl;
        // cout << o << " " << z << endl;
        cout << nCr(o + z, o) << endl;
    }
}