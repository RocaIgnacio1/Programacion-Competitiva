#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

bool check(ll num, vector<ll> &a){

}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s=0;
    forn(i,n){
        ll val;
        cin >> val;
        s+=val;
        a[i] = s;
    }

    int m;
    cin >> m;

    forn(i,m){
        ll p;
        cin >> p;
        int l=-1, r=a.size()-1;
        while((r-l)>1){
            int mid = (l+r)/2;
            if(p>a[mid]){
                l=mid;
            }else r=mid;
        }
        cout << r+1 << endl;
    }

    return 0;
}