#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

bool check(int num, vector<int> &a, int m){
    forn(i,a.size()){
        if(a[i]>num){
            return false;
        }else{
            m-=(num-a[i]);
        }
    }
    if(m>0)return false;
    else return true;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int kmax = -100000, l=0;
    forn(i,n){
        cin >> a[i];
        kmax=max(kmax,a[i]);
        l=min(l,a[i]);
    }

    int r=100*1000;
    while((r-l)>1){
        int mid = (l+r)/2;
        if(check(mid,a, m)){
            r=mid;
        }else l=mid;
    }

    cout << r << " " << kmax+m << endl;


    return 0;
}