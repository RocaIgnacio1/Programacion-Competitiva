#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define MOD 998244353

ll mod_pow(ll n, ll p){
    ll res = n % MOD;
    forn(i, p-1){
       res *= n % MOD; 
       res %= MOD;
    }
    return res;
}

int main(){
    /*freopen("input.txt", "r", stdin);*/
    ll w, h;
    cin >> w >> h;
   
    cout << mod_pow(2, w+h) % MOD << endl;

    return 0;
}
