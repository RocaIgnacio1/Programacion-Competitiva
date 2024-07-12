#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    map<int, vector<int>> dists;
    /*freopen("input.txt", "r", stdin);*/
    int N;
    cin >> N;

    forn(i, 2*N){
        int n;
        cin >> n;

        dists[n].push_back(i);
    }

    ll res = 0;
    int prev1 = 0, prev2 = 0;
    for(int i = 1; i <= N; i++){
        int diff1 = abs(prev1 - dists[i][0]);
        int diff2 = abs(prev2 - dists[i][1]);
        res += diff1 + diff2;

        prev1 = dists[i][0];
        prev2 = dists[i][1];
    }

    cout << res << endl;

    return 0;
}
