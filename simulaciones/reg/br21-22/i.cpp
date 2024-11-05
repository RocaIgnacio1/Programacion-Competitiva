#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
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

    map<string, int> days;
    days["Mon"] = 0;
    days["Tue"] = 1;
    days["Wed"] = 2;
    days["Thu"] = 3;
    days["Fri"] = 4;
    days["Sat"] = 5;
    days["Sun"] = 6;

    string day;
    int n;
    vector<ll> D;
    cin >> day >> n;
    int a = days[day];
    forn(i, n){
        ll d;
        cin >> d;
        D.push_back(d);
    }
    
    ll m = MAXN;
    forn(i, n){
        ll d = (a-D[i])%7;
        if (d < 0) d = 7 + d;
        if(D[i] == 0){
            int k = 2;
            if (d == 3) k = 4;
            if (d == 4) k = 3;
            d = (d + k) % 7;
            D[i] -= (28+k);
        }
        if (D[i] > 180){
            if (d == 0) D[i] = D[i] % 91;
            if (d == 1) D[i] = (D[i]-62)%91;
            if (d == 2) D[i] = (D[i]-61)%91;
            if (d == 3) D[i] = (D[i]-32)%91;
            if (d == 4) D[i] = (D[i]-31)%91;
            d = 0;
        }

        while(D[i] > 0){
            int k = 2;
            if (d == 3) k = 4;
            if (d == 4) k = 3;
            d = (d + k) % 7;
            D[i] -= (28+k);
        }
        m = min(m, abs(D[i]));
    }

    cout << m << endl;

    return 0;
}