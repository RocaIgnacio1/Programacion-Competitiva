#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int calculo(int r, int i){
    int primero = r/(i*2);
    int segundo = i;
    int tercero = r%i + 1;
    int cuarto = ((r/i) % 2);
    int resr = primero * segundo + tercero * cuarto;
    //cout << primero << " " << segundo << " " << tercero << " " << cuarto << " " << endl;
    resr = r + 1 - resr;
    return resr;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    forn(j,t){
        int r,l, prod = 1, i=0, minl = 1E9;
        cin >> l >> r;
        while(prod <= r){
            int resl = calculo(l-1, prod);
            int resr = calculo(r, prod);
            //cout << resl << " " << resr << endl;
            prod *= 2;
            i++;
            minl = min(minl, resr - resl);
        }
        cout << minl << endl;
    }
}