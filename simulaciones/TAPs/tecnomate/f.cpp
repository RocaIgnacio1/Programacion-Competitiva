#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int N;

int solve(vector<ll> &v, int k, int i){
    forn(j, k){
        //cout << N << endl;
        //cout << i << ' ' << v[i] << endl;
        if (i >= N){
            return -1;
        }
        i = v[i];
    }
    return i;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> N;
    vector<ll> v(N);
    forn(i, N){
        cin >> v[i];
    }

    cin >> q;
    forn(j, q){
        int k, i;
        cin >> k >> i;
        //cout << k << ' ' << i << endl;
        int ans = solve(v, k, i);
        if (ans == -1){
            cout << "Mi primera fuga de memoria\n";
        }else{
            cout << ans << endl;
        }
    }
    
    return 0;
}
