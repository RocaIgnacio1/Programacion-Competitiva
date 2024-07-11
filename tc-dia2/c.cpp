#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
vector<int> dp;

int main(){
    //freopen("input.txt", "r", stdin);
    ll t, u, v;
    cin >> t;
    forn(i,t){
        cin >> u >> v;
        
        if(u!=v){
            ll y=0;
            ll x = u*u;
            y = -v*v;

            cout << x << " " << y << endl;
        }else{
            ll x = 1, y = -1;
            cout << x << " " << y << endl;
        }
        
    }
    return 0;
}       