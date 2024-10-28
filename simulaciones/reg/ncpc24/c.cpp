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

    if(n==2){
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }
    if(n==3){
        cout << 1 << endl;
        cout << 3 << endl;
        return 0;
    }

    if(n%2==0){
        cout << (n/2) << endl;
        forn(i,(n/2)){
            cout << 2 << " ";
        }
        cout << endl;
        return 0;
    }

    if(n%3==0){
        cout << n/3 << endl;
        forn(i,(n/3)){
            cout << 3 << " ";
        }
        cout << endl;
        return 0;
    }

    if((n-1)%3==0){
        cout << ((n-1)/3)+1 << endl;
        forn(i,((n-1)/3)-1){
            cout << 3 << " ";
        }
        cout << 2 << " " << 2 << endl;
        return 0;
    }
    if((n+1)%3==0){
        cout << ((n-1)/3)+1 << endl;
        forn(i,((n+1)/3)-1){
            cout << 3 << " ";
        }
        cout << 2 << endl;
        return 0;
    }
    
    return 0;
}
