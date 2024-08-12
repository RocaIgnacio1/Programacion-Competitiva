#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
vector<int> dp;

int main(){
    ll t, u, v, x, y;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    forn(i,t){
        cin >> u >> v >> x >> y;
        ll ret1 = max(x - 1, u - x);
        ll ret2 = max(y - 1, v - y);
        

        cout << (ret1 + ret2) << endl;
    }
    return 0;
}