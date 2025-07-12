#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;

#define M_PI		3.14159265358979323846	/* pi */
 
using namespace std;

typedef long long ll;
const int MAX = 1e5;
const int MAXN = 1010;
const double EPS = 1e-9;

int n;
vector<ll> a(MAXN);
vector<ll> x(MAXN);
vector<ll> y(MAXN);

double d(int i, double l) {
    double a_rad = a[i] * (M_PI / 180.0);
    cerr << a[i] << ' ' << x[i] << ' ' << l << ' ' << y[i] << endl;
    double theta = a_rad - atan2(x[i]-l, (y[i]-MAX));
    return tan(theta) * (y[i]-MAX) + x[i];
}

double solve(int i, double l, int mask) {
    cerr << i << ": " << a[i] << ' ' << x[i] << ' ' << l << ' ' << y[i] << endl;
    bitset<32> t(mask);
    cerr << t << '\n';
    if (__builtin_popcount(mask) == n){
        return d(i, l);
    }

    double max_d = 0;
    forn(j, n){
        if (!(mask & (1<<j))) {
            dbg(j);
            double nd = solve(j, d(j, l), mask | (1<<j));
            if (nd > max_d + EPS) {
                max_d = nd;
            }
        }
    }
    return max_d;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(12);

    ll start, end;
    cin >> n >> start >> end;
    double l = (double)(start + MAX);
    double r = (double)(end + MAX);

    forn(i, n){
        cin >> x[i] >> y[i] >> a[i];
        x[i] += MAX;
        y[i] += MAX;
    }

    double max_d = solve(0, l, 1);
    // cerr << max_d-l << endl;
    // cerr << r-l << endl;
    cerr <<"ANS:"<<endl;
    cout << min(r-l, max_d-l)<< endl;
 
    return 0;
}
