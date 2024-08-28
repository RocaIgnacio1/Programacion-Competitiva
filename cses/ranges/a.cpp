#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#ifdef EBUG
#else
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n, q;
    cin >> n >> q;
    ll sum = 0;
    vector<ll> v;
    v.push_back(sum);
    forn(i, n){
        int p;
        cin >> p;
        sum += p;
        v.push_back(sum);
    }
    forn(i, q){
        int l,r;
        cin >> l >> r;
        cout << v[r] - v[l-1] << endl;
    }
}