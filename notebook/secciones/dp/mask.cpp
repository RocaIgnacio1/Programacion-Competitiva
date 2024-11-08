#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define pb push_back
typedef long long ll;
const int mod = 1e9+7; 
int n;
ll dp[22][2097152];
ll a[22][22];

ll solve(int i, ll mask, int sum){
    if(i==n){
        if(sum==n){
            return 1;
        }
        else return 0;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];

    ll ans = 0;
    forn(j,n){
        if(a[i][j]==1){
            ll aux = 0;
            aux = (1LL << j);
            if((aux&mask)==0){
                ans = ((ans%mod) + (solve(i+1,mask^aux,sum+1)%mod) %mod);
            }
        }
    }

    dp[i][mask] = ans;
    return dp[i][mask];
}

int main(){
    cin >> n;
    int valor;
    forn(i,n){
        forn(j,n){
            cin >> valor;
            a[i][j]= valor;
        }
    }
    forn(i,22){
        forn(j,2097152){
            dp[i][j]=-1;
        }
    }

    ll mask = 0;
    cout << (solve(0,mask,0)%mod) << endl;
}
