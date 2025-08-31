#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define dbg(v) cerr << #v << ": " << v;
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    HOLA
    int n;cin >> n;
    vector<int> v(n), cant(n, 0);
    forn(i, n) cin >> v[i];
    reverse(v.begin(), v.end());
    forn(i, n) cant[(i+n-(v[i]-1))%n]++;
    ll acum = 0;
    forn(i, n)acum += ((ll)cant[i] * (ll)cant[i]);
    cout << acum << endl;
    return 0;
}