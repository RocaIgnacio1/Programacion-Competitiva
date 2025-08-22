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
const ll MAXN = 10000000000;

int main() {
    HOLA;
    #ifdef EBUG
    freopen("a.txt", "r", stdin);
    #endif

    ll n,m;
    while(cin >> n >> m){
        if((max(n,m)-min(n,m))%(min(n,m))!=0){
            cout << (n*m)/2 << endl;
        }else{
            cout << (n*m)-max(n,m) << endl;
        }
    }
    
    return 0;
}