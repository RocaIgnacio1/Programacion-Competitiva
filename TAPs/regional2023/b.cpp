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
    int n, b;
    map<int,int> a;
    cin >> n;
    forn(i,3*n){
        cin >> b;
        a[b]++;
    }

    if(a.size()==1){
        cout << "N" << endl;
        return 0;
    }

    for(auto i: a){
        if(i.second%3!=0){
            cout << "Y" << endl;
            return 0;
        }
    }
    
    cout << "N" << endl;
    return 0;
}