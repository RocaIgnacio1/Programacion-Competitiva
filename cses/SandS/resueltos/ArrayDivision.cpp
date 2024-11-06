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

int n, k;
vector<ll> x;
ll bs(ll num){
    ll sum=0;
    int cant=1;
    forn(i,n){
        if(sum+x[i]<=num){
            sum+=x[i];
        }else{
            sum=0;
            sum+=x[i];
            cant++;
        }
    }
    return cant<=k;
}


int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    
    cin >> n >> k;
    ll total=0, m=0;;
    forn(i,n){
        ll a;
        cin >> a;
        x.pb(a);
        total+=a;
        m = max(m,a);
    }
    ll l=m, r=total, mid=0;
    
    while(l<=r){
        mid = (l+r)/2;
        if(bs(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    if(!bs(mid))mid++;
    cout << mid << endl;
    
    return 0;
}