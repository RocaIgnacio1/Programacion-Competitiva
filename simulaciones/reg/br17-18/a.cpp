#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif



int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<int> p;
    p.pb(a);
    p.pb(b);
    p.pb(c);
    p.pb(d);

    sort(p.begin(),p.end());

    cout << abs((p[3]+p[0]) - (p[1]+p[2])) << endl;

    
    return 0;
}