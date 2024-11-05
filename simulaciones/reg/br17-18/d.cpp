#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back
typedef long long ll;
#ifdef EBUG
//local
#else
//judge
#endif
const double pi = std::acos(-1);
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> puntajes(n);
    forn(i, n){
        cin >> puntajes[i];
    }

    sort(puntajes.begin(), puntajes.end(), greater<int>());

    ll sum = 0;
    vector<int> p;
    p.pb(puntajes[0]);
    for(int i = 1; i < n; i+=2){
        p.pb(puntajes[i]);
    }
    for(int i = n-1; i > 0; i--){
        if(i%2==0)p.pb(puntajes[i]);
    }

    sum += p[0]*p[n-1];
    forn(i,n-1){
        sum+= p[i]*p[i+1];
    }

    double angle = 360 / n;
    double ans = sum * 0.5 * abs(sin(2*pi/n));
    cout << fixed << setprecision(3) << ans << '\n';
    
    return 0;
}