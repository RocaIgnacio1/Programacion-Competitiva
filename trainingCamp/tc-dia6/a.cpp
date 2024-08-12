#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    forn(i,t){
        int n;
        cin >> n;
        vector<ll> nums;
        map<int,int> s;
        for(int j=1;j<=n;j++){
            s[j]++;
        }

        forn(j,n){
            ll valor;
            cin >> valor;
            nums.push_back(valor);
        }
        forn(j,n){
            bool bandera=true;
            while(nums[j]>=1){
                //cout << nums[j] << endl;
                if(s[nums[j]]==1){
                    s[nums[j]] = 0;
                    break;
                }
                nums[j] = nums[j]/2;
            }
           
        }
        bool ban=false;
        for(const auto& pair:s){
            //cout << pair.first << " " << pair.second << endl;
            if(pair.second==1){
                ban=true;
                break;
            }
        }
        if(ban){
            cout << "NO" << endl;
        }else{
            cout << "YES"<< endl;
        }
    }

    
}