#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) for(auto i : v) cout << i << " ";
#define pb push_back
#define pp pop_back
#define F first
#define S second
const int mod=1e9+7;
const int MAX=3e5+10;
const ll INF = 1e18+100;
typedef long double ld;
const ld EPS = 1e-9;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int l,r;
        cin >> l >> r;
        if(l==r) {
            cout << 0 << endl;
            continue;
        }
        vector <int> nums;
        for(int i=l;i<=r;i++){
            nums.pb(i);
        }
        int ans=0;
        for(int i=0;  i<nums.size()-2;i++){
            int a = gcd(nums[i], nums[i+1]);
            int b = gcd(nums[i], nums[i+2]);
            int c = gcd(nums[i+1], nums[i+2]);
            if(a==1&&b==1&&c==1){
                //cout << nums[i] << " " << nums[i+1] << " " << nums[i+2] << endl;
                ans++;
                i+=2;
                
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}
