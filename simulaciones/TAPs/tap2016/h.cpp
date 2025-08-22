#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

typedef long double ld;
const int MAXN = 1010;

ld P[MAXN][MAXN];

int main() {
    HOLA;
    #ifdef EBUG
    freopen("h.txt", "r", stdin);
    #endif

    int n, x, y;
    cin >> n >> x >> y;

    forn(i, n){
        P[0][i] = 1/(ld)n;
    }
    
    forn(i, n){
        ld sum = 0;
        forn(j, n){
            cout << i << ' ' << j << ' ' << P[i][j] << endl;
            P[i+1][j] = P[i][j] *  + (ld)((ld)2/((ld)n-(ld)(i+1))) * (1-sum);
            sum += P[i][j];
        }
    }

    cout << fixed << setprecision(8) << P[y][x-1] << endl;
    
    return 0;
}