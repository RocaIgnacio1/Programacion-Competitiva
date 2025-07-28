#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
const int MAXX = 1e6+1;

int main(){
    HOLA;
    int n; cin >> n;

    vector<int> a(n+1);
    vector<bool> apper(MAXX, false);
    forn(i, n){
        cin >> a[i];
    }

    int max_div = 1;
    forn(i, n){
        for (int x = 1; x*x <= a[i]; ++x) {
            if (a[i] % x == 0) {
                // divisors.push_back(x);
                if (apper[x]) {
                    max_div = max(max_div, x);
                }
                apper[x] = true;

                if (x != a[i] / x){
                    int div = a[i] / x;
                    if (apper[div]) {
                        max_div = max(max_div, div);
                    }
                    apper[div] = true;
                }
            }
        }
    }
    cout << max_div << endl;
 
    return 0;
}
