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
        cin >> n;
        vector<int> p;
        forn(i,n){
            int valor;
            cin >> valor;
            p.push_back(valor);
        }
        
        //cout << "hola" << endl;
        cout << p[n-1] << " ";
        forn(i,n-1){
            cout << p[i] << " ";
        }
        cout << endl;

    }
    
}
