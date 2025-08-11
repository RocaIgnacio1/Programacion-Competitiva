#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    t=1;
    while(t--){
        int n;
        cin >> n;
        vector<ll> nums(n),pot;
        forn(i,n){
            cin >> nums[i];
        }
        ll s=1;
        while(s<2000000000){
            pot.push_back(s);
            s*=2;
        }
        reverse(pot.begin(),pot.end());
        forn(i,pot.size()){
            int sum=0;
            forn(j,n){
                if(nums[j]%pot[i]==0)sum++;
            }
            if(sum>0){
                cout << pot[i] << " " << sum << endl;
                break;
            }
        }
    }

    return 0;
}