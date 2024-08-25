#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)

typedef long long ll;
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<ll> A;
    ll max = 0;
    forn(i, n){
        ll a;
        cin >> a;
        if (a > max){
            max = a;
        }
        A.push_back(a); 
    }

    sort(A.begin(), A.end());
    ll min = A[0];
    ll res = min * min + min * min + max * max - (min*max + min*min + max*min);
    cout << res << endl;

    return 0;
}