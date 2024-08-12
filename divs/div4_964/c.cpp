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
        ll n,s,m;
        cin >> n >> s >> m;
        ll finalAnterior=0;
        bool ban=false;
        forn(i,n){
            ll l,r;
            cin >> l >> r;

            if(l-finalAnterior >= s){
                ban=true;
            }
            if(i==n-1 && m-r>=s) ban=true;

            finalAnterior=r;
        }

        if(ban){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
