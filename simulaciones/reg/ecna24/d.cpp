#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
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
    ios :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N, KWF;
    int prom = 0;
    forn(i, 5){
        int a, l;
        cin >> a >> l;
        prom += (a * l);
    }
    cin >> N >> KWF;
    prom /= 5;
    int ans = prom * N / KWF;
    
    cout << ans << '\n';
    
    return 0;
}