#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;
const ll MAXN = 10000000000;
 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    int t;
    cin >> t;
    forn(k,t){
        int n;
        cin >> n;
        vector<vector<ll>> numeros;
        forn(i,n){
            vector<ll> p(n);
            forn(j,n){
                cin >> p[j];
            }
            numeros.push_back(p);
        }
        cout << 998244353 << endl;
        
    }
   
    return 0;
}
