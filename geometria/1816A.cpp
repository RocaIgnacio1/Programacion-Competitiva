#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define mos(v) for(auto i : v) cout << i << " ";
typedef long long T;
typedef long double ld;
const T EPS = 1e-9;
const T INF = 1e18;

int main() {
    int t;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        ll a,b;
        cin >> a >> b;
        if(a==b && a==1){
            cout << 1 << endl;
            cout << a << " " << b << endl;
            continue;
        }
        cout << 2 << endl;
        cout << a-1 << " " << 1 << endl;
        cout << a << " " << b << endl;
        
    }
    return 0;
}
