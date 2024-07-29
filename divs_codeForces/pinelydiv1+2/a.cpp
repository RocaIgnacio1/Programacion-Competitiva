#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    forn(w,t){
        int n;
        vector<int> a;
        cin >> n;
        int ans=0;
        forn(i,n){
            int valor;
            cin >> valor;
            a.pb(valor);
        }
        int maximo=0;
        forn(i,n){
            if(i%2==0){
                maximo = max(maximo,a[i]);
            }
        }

        cout << maximo << endl;
    }
    return 0;
}
