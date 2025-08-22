#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000


bool check(ll mid, int k, vector<ll> &a){
    vector<ll> particion(a.size()+11,0);
    ll distinct=0; int p=0;
    forn(i,a.size()){
        if(a[i]>a.size()+5)continue;
        if(particion[a[i]]==0 && a[i]<mid){
            particion[a[i]]=1;
            distinct++;
        }
 
        if(distinct>=mid){
            distinct=0;
            for (int j=0; j<min(mid+1,(ll)a.size()+2); j++) {
                particion[j] = 0;
            }
            p++;
        }
    }
    return p>=k;
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
        int n,k;
        cin >> n >> k;
        vector<ll> a(n);
        forn(i,n){
            cin >> a[i];
        }

        ll l=0, r=1000000001;
        while((r-l)>1){
            ll mid = (r+l)/2;
            if(check(mid,k,a)){
                l=mid;
            }else r=mid;
        }
        cout << l << endl;
    }
    return 0;
}