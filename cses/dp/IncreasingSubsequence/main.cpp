#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;
#define endl '\n'

typedef long long ll;

using namespace std;

const int MAXN = 2*1e5+10;

int main() {
    int n;
    cin >> n;
    vector<int> dp;
    forn(i, n) {
        int x; cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << dp.size() << endl;
    return 0;
}
