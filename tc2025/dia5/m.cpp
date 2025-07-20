#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

typedef long long ll;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int n; cin >> n;
    vector<int> x(n+1);
    forn(i, n) cin >> x[i];
    int q; cin >> q;
    vector<int> m(q+1);
    forn(i, q) cin >> m[i];

    sort(x.begin(), x.end());
    //cout << "====" << endl;
    forn(i, q){
        auto it = upper_bound(x.begin(), x.end(), m[i]);
        if (it == m.begin()) {
            cout << 0 << endl;
        }else{
            cout << it - x.begin()-1 << endl;
            int pos = x.end() - it;
            //cout << pos << endl;
        }
    }
    
    return 0;
}