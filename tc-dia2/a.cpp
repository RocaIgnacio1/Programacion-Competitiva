#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
vector<int> dp;

int main(){
    int n;
    vector<ll> r;
    cin >> n;
    forn(i, n){
        ll p;
        cin >> p;
        r.push_back(p);
    }
    ll max1 = 10000000000;
    ll r1 = max1, r2 = max1, r3 = max1;
    int a, b, c;
    bool ban = false;
    forn(i, n){
        if(r[i] < r1){
            r1 = r[i];
            a = i;
            ban = true;
        }
    }
    if(ban) r[a] = max1;
    ban = false;
    forn(i, n){
        if(r[i] < r2 && r[i] != r1){
            r2 = r[i];
            b = i;
            ban = true;
        }
    }
    if(ban) r[b] = max1;
    ban = false;
    forn(i, n){
        if(r[i] < r3 && r[i] != r1 && r2 != r[i]){
            r3 = r[i];
            c = i;
            ban = true;
        }
    }
    if(ban) r[c] = max1;
    ban = false;
    if(r1 != max1 && r2 != max1 && r3 != max1){
        cout << a + 1<< " " << b + 1<< " " << c + 1 << endl;
    }else{
        cout << "-1 -1 -1" << endl;
    }
    return 0;
}