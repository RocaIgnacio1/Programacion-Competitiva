#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    forn(j,t){
        int r,l, prod = 1, i=0, minl = 1E9;
        cin >> l >> r;
        while(prod <= r){
            int auxr = (((r+prod)/(prod*2))-1);
            int auxl = (((l+prod)/(prod*2))-1);
            if(auxl < 0) auxl = 0;
            if(auxr < 0) auxr = 0;
            int resr = auxr *prod + (r%prod) * ((r/prod) % 2);
            int resl = auxl *prod + (l%prod) * ((l/prod) % 2);
            //cout << resl << " " << resr << endl;
            minl = min(minl, resr - resl);
            prod *= 2;
            i++;
        }
        cout << minl << endl;
    }
}