#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main() {
    freopen("input.txt","r",stdin);
    
    int M;
    vector<double> nums;
    cin >> M;

    forn(i, 2*M){
        double n;
        cin >> n;
        nums.push_back(n);
    }

    double res = 0.0;
    int c = 1;
    for (int i = M; i < 2*M; i++){
        res += c / nums[i];
        cout << fixed << setprecision(6) << res << endl;
        c++;
    }
    cout << endl;

    c = 1;
    res = 0.0;
    for (int i = M-1; i >= 0; i--){
        res += c / nums[i];
        cout << fixed << setprecision(6) << res << endl;
        c++;
    }

    return 0;
}
