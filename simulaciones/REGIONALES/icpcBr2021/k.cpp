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

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, D, M;
    int prev = 0;
    int maxDiff = 0;
    cin >> T >> D >> M;
    forn(i, M){
        int y;
        cin >> y;
        maxDiff = max(maxDiff, abs(y - prev));
        prev = y;
    }
    maxDiff = max(maxDiff, abs(D - prev));

    if (T <= maxDiff){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}