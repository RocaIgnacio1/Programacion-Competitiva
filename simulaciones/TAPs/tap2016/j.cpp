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

    int n,l,c;
    cin >> n >> l >> c;
    vector<int> a(n);
    forn(i,n){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int k=0;
    forn(i,n){
        if(k==0){
            k=l;
            c-=a[i];
            if(c<0){
                cout << "N" << endl;
                return 0;
            }
        }
        k--;
    }
    cout << "S" << endl;
    return 0;
}