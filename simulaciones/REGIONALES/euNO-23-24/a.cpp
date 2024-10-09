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



void may(deque<ll> &a, deque<ll> &b, deque<ll> &c){
    ll uno=0, dos=0, tres=0;
    if(!a.empty())uno=a.back();
    if(!b.empty())dos=b.back();
    if(!c.empty())tres=c.back();

    if(uno>dos && uno>tres)a.pop_back();
    if(dos>uno && dos>tres)b.pop_back();
    if(tres>uno && tres>dos)c.pop_back();

}

bool calc(int k){
    deque<ll> uno,dos,tres;
    ll a = s-2;
    forn(i,k){
        if(c[i]%3==0)uno.pb(c[i]);
        if(c[i]%3==1)dos.pb(c[i]);
        if(c[i]%3==2)tres.pb(c[i]);
    }
    
    may(uno,dos,tres);
    may(uno,dos,tres);
  
    forn(i,uno.size()){
        a = a - (uno[i]/3);
    }
    
    while(dos.size()>0 && tres.size()>0){
        a = a - ((dos.front()+tres.front()+2)/3);
        dos.pop_front();
        tres.pop_front();
    }
    while(dos.size()>0){
        if(dos.size()>=2){
            a = a - ((dos.front()+dos.front()+2)/3);
            dos.pop_front();
            dos.pop_front();
        }else{
            a = a - ((dos.front()+2)/3);
            dos.pop_front();
        }
    }
    while(tres.size()>0){
        a = a - ((tres.front()+2)/3);
        tres.pop_front();
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
