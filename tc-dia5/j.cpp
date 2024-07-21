#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);

    vector<int> occurs(110, 0);
    vector<int> nums;
    int n, k;
    cin >> n >> k;
    forn(i, n){
        int a;
        cin >> a;
        nums.push_back(a);
        occurs[a] = 1;
    }

    int idx = 0;
    vector<int> res;
    for(int i : nums){
        if (occurs[i] == 1){
            occurs[i] = 0;
            res.push_back(idx+1);
        }
        idx ++;
    }

    if (res.size() < k){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        forn(w, k){
            cout << res[w] << " ";
        }
        cout << endl;
    }
}