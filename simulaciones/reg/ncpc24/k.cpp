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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, p;
    cin >> n >> p;

    if(n%p == 0){
        cout << 0 << endl;
        return 0;
    }
    ll sobran = n%p;
    if( sobran%2 == 0){
        if(((n-sobran)/p)%2==0){
            cout << sobran+p << endl;
        }
        else cout << sobran << endl;
        return 0;
    }
   cout << sobran+p << endl;
    return 0;
}