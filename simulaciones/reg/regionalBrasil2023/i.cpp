#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
typedef long long ll;

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
    ll mod = 1e9+7;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif
    string s, diccionario = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    ll n;
    cin >> n;
    map<char, int> abc, imp;
    for(auto i: diccionario){
        abc[i] = 0;
        imp[i] = 0;
    }
    vector<int> may;
    for(auto i:s){
        int con = 'a';
        for(auto j: abc){
            if(j.first == i){
                abc[con]++;
                break;
            }
            abc[con]++;
            imp[con]++;
            con++;
        }
        may.push_back(abc[i+1]);
    }
    ll sum = 0;
    int con = 0;
    for(auto i: s){
        sum += ((n%mod) * may[con] + ((((n%mod)*((n%mod)-1))/2)%mod)*imp[i])% mod;
        sum %= mod;
        con++;
    }
    cout << sum << endl;
}