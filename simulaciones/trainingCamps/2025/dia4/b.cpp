#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> Xcount, Ycount, Zcount;
        vector<int> X(n), Y(n), Z(n), d(n);
        forn(i, n){
            cin >> X[i] >> Y[i] >> Z[i]; 
            Xcount[X[i]]+=1;
            Ycount[Y[i]]+=1;
            Zcount[Z[i]]+=1;
        }
        forn(i, n){
            d[i] = max(Xcount[X[i]], max(Ycount[Y[i]], Zcount[Z[i]]));
        }
        // forn(i, n){
        //     cout << i << ": " << d[i] << endl;
        // }
        
        map<int, int> densityCount;
        forn(i, n){
            densityCount[d[i]]++;
        }
        // cout << "====" << endl;
        int sum = 0;
        forn(i, n){
            sum += densityCount[i];
            cout << sum << ' ';
        }
        cout << endl;
    }

    return 0;
}
