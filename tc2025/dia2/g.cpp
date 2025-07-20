#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define ll long long

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

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    forn(i, n){
        int k;
        cin >> k;
        v.push_back(k);
    }
    int mn = 1000000009;
    ll acum = 0;
    reverse(v.begin(), v.end());
    forn(i, n){
        mn --;
        mn = min(v[i], mn);
        if(mn>0)acum+=mn;
    }

    cout << acum << endl;
    
    return 0;
}