#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);

    int n;
    ll m;
    cin >> n >> m;
    vector<ll> S(n);

    forn(i, n){
        cin >> S[i];
    }
    
    for (int i = n-2; i >= 0; i--){
        S[i] = max(S[i], S[i+1] - m);
    }

    for (int i = 1; i < n; i++){
        S[i] = max(S[i], S[i-1] - m);
    }

    forn(i, n){
        cout << S[i] << ' ';
    }
    cout << '\n';

    return 0;
}
