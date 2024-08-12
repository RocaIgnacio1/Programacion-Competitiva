
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    
    forn(i,t) {
        int n;
        cin >> n;
        map<int,int> nums;
        int maximo=0;
        forn(j,n){
            int a;
            cin >> a;
            nums[a]++;
        }
        bool bandera=true;
        for(const auto& pair:nums){
            if(pair.second %2 !=0){
                cout << "YES" << endl;
                bandera=false;
                break;
            }
        }
        if(bandera) cout << "NO" << endl;
    }

    return 0;
}

