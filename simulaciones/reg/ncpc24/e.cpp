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
    int n;
    cin >> n;
    int x = 0, y = 0;
    forn(i, n){
        int x2, y2;
        cin >> x2 >> y2;
        if(x2 > x){
            forn(i, x2-x){
                cout << '>';
            }
        }else{
            forn(i, x-x2){
                cout << '<';
            }
        }
        if(y2 > y){
            forn(i, y2-y){
                cout << '^';
            }
        }else{
            forn(i, y-y2){
                cout << 'v';
            }
        }
        x = x2;
        y = y2;

    }
    
    
    return 0;
}
