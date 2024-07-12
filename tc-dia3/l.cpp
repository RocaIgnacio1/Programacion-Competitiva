#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define MAXN 200001

int main(){
    int t;
    ll x, y;
    cin >> t;
    forn(i, t){
        cin >> x >> y;
        if (x-y == 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
