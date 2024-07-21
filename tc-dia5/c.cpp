#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define print()

int main(){
    //freopen("input.txt", "r", stdin);
    
    ll n, M;
    cin >> n >> M;
    vector<ll> nums;
    int ons = 0;
    int offs = 0;

    forn(i, n){
        ll a;
        cin >> a;
        nums.push_back(a);
    }
    ons = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if (i % 2 == 0){
            ons  += abs(nums[i] - nums[i-1]);
        }else{
            offs += abs(nums[i] - nums[i-1]);
        }
    }
    if (n % 2 == 0){
        ons += abs(M - nums[n-1]);
    }else{
        //cout << nums[n-1] << endl;
        offs += abs(M - nums[n-1]);
    }

    //cout << ons << endl;
    //cout << offs << endl;

    int onsI = 0;
    int offsI = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        int rango; 
        if (i > 0){
            rango = abs(nums[i] - nums[i-1]);
        }else{
            rango = nums[i];
        }
    
        int onsD  = ons  - onsI;
        int offsD = offs - offsI;
        int sum = onsI + offsD;
        //cout << onsD << " " << offsD << endl;
        //cout << "sum: " << sum << endl;

        if (i % 2 == 0){

            if(rango!=1) res = max(res, onsI - 1 + offsD);
            onsI += rango;
        }else{
            if(rango!=1) res = max(res, onsI +  rango - 1 + offsD);
            offsI += rango;
        }
        

    }
    cout << "res:" << res << endl;
}