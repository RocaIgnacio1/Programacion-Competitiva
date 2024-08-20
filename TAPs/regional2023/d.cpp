#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int n,g;
    vector<string> pal;
    string corr;
    cin >> n;
    cin >> corr;
    forn(i,n){
        string s;
        cin >> s;
        pal.push_back(s);
    }
    forn(i,g){
        string s;
        cin >> s;
        for(auto j: s){
            for(auto k: pal){
                for(auto l: k){
                    if
                }
            }
        }
    }
    


    return 0;
}