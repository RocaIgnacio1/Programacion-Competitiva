#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt","r",stdin);
    int n,m,x,y;
    cin >> n >> m;
    cin >> x >> y;

    ll prom1, prom2;
    prom1 = (ll)(x*m + y*n)*(ll)(n+m);
    prom2 = (ll)(n*m) * (ll)(x+y) * (ll) 2;
    //cout << prom1 << " " << prom2;
    if(prom1 > prom2){
        cout << "A";
    }else if(prom2 > prom1){
        cout << "B";
    }else{
        cout << "C";
    }
    cout << endl;
}