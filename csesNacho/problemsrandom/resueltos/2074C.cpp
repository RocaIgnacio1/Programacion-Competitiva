#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    vector<ll>pot;
    ll s=1;
    while(s<10000000000){
        pot.push_back(s);
        s*=2;
    }

    cout << endl;
    int tt;
    cin >> tt;
    while(tt--){
        ll x,y;
        cin >> x;
        forn(i,pot.size()){
            if(pot[i]>x){
                y = pot[i-1]-1;
                break;
            }
        }
        ll xy=x^y;
        if(x+y>xy && x+xy>y && xy+y>x){
            cout << y << endl;
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}