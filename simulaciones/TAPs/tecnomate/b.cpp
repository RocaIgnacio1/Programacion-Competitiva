#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif
int n;
ll m;
vector<ll> b;

bool calc(ll mid){
    ll sum=0;
    forn(i,n){
        if(b[i]<=mid){
            sum+=1;
        }else{
            sum += (b[i]/mid);
            if(b[i]%mid!=0)sum++;
        }
    }

    if(sum<=m)return true;
    else return false;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    ll maximo=0;
    forn(i,n){
        ll a;
        cin >> a;
        b.pb(a);
        maximo = max(maximo,a);
    }

    ll l=1, r=maximo, mid=0;
    while(l<=r){
        mid = (l+r)/2;
        if(!calc(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
        //cout << mid << endl;
    }
    if(!calc(mid))mid++;
    cout << mid << endl;
    
    return 0;
}
