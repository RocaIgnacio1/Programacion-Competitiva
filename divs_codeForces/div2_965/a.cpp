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
        ll x,y,k;
        cin >> x >> y >> k;
       
        vector<ll> equis;
        vector<ll> ye;
        if(k%2==1){
            equis.push_back(x);
            ye.push_back(y);
        }
        forn(i,k/2){
            equis.push_back(x-1);
            ye.push_back(y-i);
            equis.push_back(x+1);
            ye.push_back(y+i);
        }


        forn(i,k){
            cout << equis[i] << " " << ye[i] << endl;
        }

    }
    return 0;
}
