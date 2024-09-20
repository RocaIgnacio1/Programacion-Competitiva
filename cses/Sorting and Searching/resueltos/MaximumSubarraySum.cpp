#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<ll> nums(n);
    forn(i,n){
        cin >> nums[i];
    }
    ll sum=nums[0], ans=nums[0];
    forn(i,n){
        if(i==0)continue;
        sum = max(nums[i],nums[i]+sum);
       
        ans = max(ans,sum);
    }
   
    cout << ans << endl;

    return 0;
}