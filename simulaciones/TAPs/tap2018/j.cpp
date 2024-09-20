#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define MOD 1000000007

ll fill_pows(vector<ll> &a, int n, int N){
    a[0] = 1;
    a.resize(n);
    cout << a[1] << endl;
    forn(i, N-1){
        a[i+1] = (a[i] % MOD * n % MOD) % MOD;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int N;
    string s;

    cin >> N;
    cin >> s;
    vector<ll> pows26(N);
    vector<ll> pows25(N);

    fill_pows(pows26, 26, N);
    fill_pows(pows25, 25, N);
 
    ll res = 0;
    forn(i, N){
        res = res + (pows26[i] * pows25[N-1-i]) % MOD;
    }
    cout << res << endl;

    return 0;
}