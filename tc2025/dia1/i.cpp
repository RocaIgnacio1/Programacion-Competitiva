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
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> A(n);
        forn(i, n){
            cin >> A[i];
        }
        ll score = -1;
        for(ll k = 1; k <= n; k++){ // tamaño de la subsecuencia
            cout << "K = " << k << " " << endl;
            for(int i = 0; i < n-k+1; i++){ // comienzo
                ll sum = 0;
                for(int j = 0; j < k; j++){
                    cout << A[i+j] << " ";
                    sum = sum | A[i+j];
                }
                cout << "= " << sum << "| " << k - __builtin_popcountll(sum) << endl;
                score = max(score, k - __builtin_popcountll(sum));
            }
        }
        cout << "SCORE:" << score << '\n';
    }
    
    return 0;
}