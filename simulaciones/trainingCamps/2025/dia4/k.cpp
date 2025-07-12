#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

using namespace std;

const int MAXN = 15;

int n;
vector<int> t1(MAXN);
vector<int> t2(MAXN);
vector<int> t3(MAXN);

int solve(int i, int sum) {
    if (i >= n) return 0;

    int a = 0, b = 0, c = 0;
    if (sum + t1[i] <= 300 && t1[i] != -1) {
        a = solve(i+1, sum + t1[i]) + 1;
    }    
    if (sum + t2[i] <= 300 && t2[i] != -1) {
        b = solve(i+1, sum + t2[i]) + 1;
    }
    if (sum + t3[i] <= 300 && t3[i] != -1) {
        c = solve(i+1, sum + t3[i]) + 1;
    }
    int d = solve(i+1, sum);
    return max(max(a, b), max(c, d));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    forn(i, n){
        string s;
        cin >> s >> t1[i] >> t2[i] >> t3[i];
        // cout << s << t1[i] << t2[i] << t3[i] << endl;
    }

    cout << solve(0, 0) << endl;

    return 0;
}
