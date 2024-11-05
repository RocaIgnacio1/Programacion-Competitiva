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

bool esprimo(ll p){
    for(int j=2; j*j<=p ;j++){
        if(p%j==0){
            return false;
        }
    }

    return true;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll a;
    cin >> a;
    for(int i=a ; i>0 ; i--){
        if(esprimo(i)){
            cout << i << endl;
            return 0;
        }
    }

    
    return 0;
}