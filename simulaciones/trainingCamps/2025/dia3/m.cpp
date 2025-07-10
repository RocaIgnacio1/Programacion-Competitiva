#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a, b, m, r;
    cin >> a >> b >> m >> r;

    map<int, int> appers;
    int i = 0, last;
    while(true) {
        r = (a*r + b) % m;
        // cerr << "====" << r << endl;
        // for(auto s : appers){
        //     cerr << s.first <<": " << s.second << endl;
        // }
        last = r;
        if (appers.find(r) != appers.end()) break;
        appers[r] = i;
        i++;
    }

    // cerr << i << endl;
    // cerr << last << endl;
    cout << i - appers[last] << '\n';

    return 0;
}
