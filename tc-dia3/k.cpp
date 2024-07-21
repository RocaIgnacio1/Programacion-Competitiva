#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
<<<<<<< HEAD
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
=======
    freopen("input.txt", "r", stdin);

    int N;
    string s;
    cin >> N;
    cin >> s;

    int c = 0;
    forn(i, N){
        int n = s[i]-'0';
        if (n % 2 == 0){
            c += 1+i;
        }
    }
    cout << c << endl;
}
>>>>>>> 3d7bf9b (tc days 3,4,5,6)
