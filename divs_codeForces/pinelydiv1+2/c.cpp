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
        vector<ll> a;
        cin >> n;
        forn(i,n){
            ll valor;
            cin >> valor;
            a.pb(valor);
        }
        bool par=false, impar=false;

        forn(i,n){
            if(a[i]%2==0){
                par=true;
            }else{
                impar=true;
            }
        }
        if(par && impar) cout << -1 << endl;
        else{

            vector<int> operations;
            for (int i = 29; i >= 0; i--)
                operations.push_back(1 << i);
            if (par)
                operations.push_back(1);

            cout << operations.size() << endl;
            for (int x : operations)
                cout << x << ' ';
            cout << endl;
        }
    }   
    return 0;
}
