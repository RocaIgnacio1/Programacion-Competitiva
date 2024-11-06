#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int n;
ll s;
vector<ll> c;

bool calc(int k){
    if(k==1 || k==0 || k==2)return true;
    deque<ll> cero,uno,dos;
    ll a = s-2;
    forn(i,k-2){
        if(c[i]%3==0)cero.pb(c[i]);
        if(c[i]%3==1)uno.pb(c[i]);
        if(c[i]%3==2)dos.pb(c[i]);
    }
  
    while(cero.size()>0){
        a = a - (cero.front()/3);
        cero.pop_front();
        if(a<0) return false;
    }
    
    while(uno.size()>0 && dos.size()>0){
        a = a - ((uno.front()+dos.front()+2)/3);
        uno.pop_front();
        dos.pop_front();
        if(a<0) return false;
    }
    while(uno.size()>0){
        if(uno.size()>=2){
            a = a - ((uno[0]+uno[1]+2)/3);
            uno.pop_front();
            uno.pop_front();
        }else{
            a = a - ((uno.front()+2)/3);
            uno.pop_front();
        }
        if(a<0) return false;
    }
    while(dos.size()>0){
        a = a - ((dos.front()+2)/3);
        dos.pop_front();
        if(a<0) return false;
    }

    if(a<0) return false;
    else return true;
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    forn(i,n){
        ll a;
        cin >> a;
        c.push_back(a);
    }
    sort(c.begin(),c.end());
    
    if(s==1){
        cout << 1 << endl;
        return 0;
    }
    
    int l=0, r=n, mid=0;
    while(l<=r){
        mid = (l+r)/2;

        if(calc(mid)){
            l=mid+1;
        }else r=mid-1;
    }

    if(!calc(mid))mid--;
    
    cout << mid << endl;
    
}
