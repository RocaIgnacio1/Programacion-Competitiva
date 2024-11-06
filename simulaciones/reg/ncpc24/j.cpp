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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<pair<int,int>> a;
    cin >> n;
    
    
    forn(i,n){
        int p,s;
        cin >> p >> s;
        a.pb(make_pair(p,s));
    }
    if(n==1 && a[0].first==2 && a[0].second==2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> p(n+1);
    vector<int> s(n+1);
    forn(i,n+1)s[i]=0;
    forn(i,n+1)p[i]=0;
    forn(i,n){
        if(a[i].first <= n ){
            p[a[i].first]=1;
        }
        if(a[i].second <= n ){
            s[a[i].second]=1;
        }
    }

    int val=0;

    for(int i=2 ; i<=n ; i++){
        if(p[i]==0 && i%2==0){
            val=i;
            break;
        }
    }
    if(val!=0){
        forn(i,n){
            cout << i+1 << " " << val/2 << endl;
        }
        return 0;
    }
    
    val=0;
    for(int i=2 ; i<=n ; i++){
        if(s[i]==0 && i%2==0){
            val=i;
            break;
        }
    }
    if(val!=0){
        forn(i,n){
            cout << i+1 << " " << val/2 << endl;
        }
        return 0;
    }

    
    forn(i,n){
        if(a[i].first==2){
            val = a[i].first;
        }
    }
    forn(i,n-1){
        cout << i+2 << " " << val/2 << endl;
    }
    if(val/2 % 2 == 0){
        cout << 1 << " " << 1 << endl;
    }else{
        cout << 2 << " " << 2 << endl;
    }

    
    return 0;
}