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

#define MAXN 300000
#define operacion(x, y) op(x, y)
#define neutro {-1, 0, 0}
#define tipo tuple<int, int, int> // {ganas o perdes, cacheTotal, acumx, acumy}

int main() {
    HOLA
    int n;
    cin >> n;
    vector<int> v;
    vector<int> cant(n, 0);
    forn(i, n){
        int k;
        cin >> k;
        v.push_back(k);
    }

    reverse(v.begin(), v.end());
    forn(i, n){
        //cout << i << " " << v[i]-1 << " " << (i+n-(v[i]-1))%n << endl;
        cant[(i+n-(v[i]-1))%n]++;
    }
    ll acum = 0;
    forn(i, n){
        acum += (pow(cant[i], 2));
    }
    cout << acum << endl;
    return 0;
}