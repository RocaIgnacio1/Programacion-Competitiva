#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;
#define pb push_back

using namespace std;

const int MAXN = 1010;

int l[MAXN];
int q = 0;

bool is_less(int i, int j){
    cout << "? " << i+1 << ' ' << j+1 << endl;
    cout.flush();
    string ans; cin >> ans;
    return ans == "YES";
}

// bool is_less(int i, int j){
//     q++;
//     return l[i] < l[j];
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> idx, a(n+1);
    forn(i, n) idx.pb(i);
    // forn(i, n) cin >> l[i];

    stable_sort(idx.begin(), idx.end(), is_less);

    forn(i, n) {
        a[idx[i]] = i + 1;
    }

    cout << "! ";
    forn(i, n) {
        cout << a[i] << ' ';
    }
    cout << endl;
    dbg(q);

    return 0;
}
