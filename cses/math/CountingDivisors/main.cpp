#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;

map<int, int> factors(int n) {
    map<int, int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f[x]++;
            n /= x;
        }
    }
    if (n > 1) f[n]++;
    return f;
}

int main(){
    HOLA
    int t; cin >> t;

    while(t--){
        ll a; 
        cin >> a;
        auto facts = factors(a);
        ll ans = 1;
        for (auto f : facts) {
            ans *= f.second+1;
        }
        cout << ans << endl;
    }
 
    return 0;
}
