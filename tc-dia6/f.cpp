#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    int t;
    cin >> t;
    forn(i,t){
        int a,b,n;
        cin >> a >> b >> n;
        int maxl = max(a,b);
        int minl = min(a,b);
        int con = 0;
        while(maxl <= n){
            con++;
            int aux = minl;
            minl = maxl;
            maxl += aux;
        }
        cout << con << endl;
    }

    
}