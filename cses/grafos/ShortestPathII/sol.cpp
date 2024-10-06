#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef unsigned long long ll;
typedef pair<ll, ll> ii;
const ll MAXN = LONG_LONG_MAX;

/* Solucion: 
 * Floyd marshall
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<ii> queries;

    vector<vector<ll>> distance(n, vector<ll>(n, MAXN));
    forn(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        distance[a][b] = min(distance[a][b], c);
        distance[b][a] = min(distance[a][b], c);
    }
    forn(i, n){
        distance[i][i] = 0;
    }

    forn(i, q){
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    forn(k, n){
        forn(i, n){
            forn(j, n){
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(auto [a, b] : queries){
        a--; b--;
        if (distance[a][b] == MAXN) cout << "-1\n";
        else cout << distance[a][b] << '\n'; 
    }
    return 0;
}
