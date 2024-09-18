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

int n;
vector<ll> k;
ll t;

bool func(ll tiempo){
    ll sum=0;
    forn(i,n){
        sum+= tiempo/k[i];
    }

    if(sum>=t)return true;
    else return false;
}

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
   
    cin >> n >> t;
    ll tmin=9000000000000000000;
    forn(i,n){
        ll a;
        cin >> a;
        k.push_back(a);
        tmin = min(tmin, k[i]);
    }
    ll l=1, r=t*tmin, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(!func(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    
    if(!func(mid))mid++;
    cout << mid << endl;
    

    return 0;
}