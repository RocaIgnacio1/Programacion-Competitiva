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

const int MAX_N=110;
const int INF = 1e9;

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    int adj[MAX_N][MAX_N];
    
    forn(i, n){
        forn(j, n){
            cin >> adj[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k == i || k == j) continue;
                if (adj[i][j] > adj[i][k] + adj[k][j]){
                    cout << - 1 << endl;
                    return 0;
                }
            }
        }
    }

    int ans = 0;
    forn(i, n){
        forn(j, n){
            bool sacar = false;
            forn(k, n){
                if (k == i || k == j) continue;
                if (adj[i][j] == adj[i][k] + adj[k][j]){
                    sacar = true;
                    break;
                }
            }
            if (sacar) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}