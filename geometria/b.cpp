#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double


int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    forn(w,t){
        int n,k;
        cin >> n >> k;
        vector<string> a;
        forn(i,n){
            string valor;
            cin >> valor;
            a.push_back(valor);
        }
        /*
        forn(i,n){
            cout << a[i] << endl;
        }
        */
        vector<char> ans[n/k]; // n/k 
        int p=0;
        for(int j=0; j<n;j+=k){
            for(int i=0; i<n; i+=k){
                //cout << a[i][j] << " ";
                ans[p].push_back(a[j][i]);
            }
            //cout << endl;
            p++;
        }

        forn(i,n/k){
            forn(j,n/k){
                cout << ans[i][j];
            }
            cout << endl;
        }
       
    }
    return 0;
}
