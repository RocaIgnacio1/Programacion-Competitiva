#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000


bool check (ll n, ll m, ll mid, ll k){
  
    k -= n * ( (mid * (m/(mid+1)) ) + (m%(mid+1)) ); 
    return (k<=0);
}   

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        ll n,m,k;
        cin >> n >> m >> k;
        
        ll l=0, r=m;
        while((r-l)>1){
            ll mid = (r+l)/2;
            if(check(n,m,mid,k)){
                r=mid;
            }else l=mid;
        }
        cout << r << endl;
    }

    return 0;
}