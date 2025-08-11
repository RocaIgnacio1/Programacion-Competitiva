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
    freopen("input.txt", "r", stdin);
    #endif
    int d, c, r;
    cin >> d >> c >> r;
    vector<int> C, R;
    forn(i, c){
        int k;
        cin >> k;
        C.push_back(k);
    }

    forn(i, r){
        int k;
        cin >> k;
        d+= k;
    }
    int con = 0;
    forn(i, c){
        d-=C[i];
        if(d>=0) con++;
    }

    cout << con + r << endl;

    return 0;
}