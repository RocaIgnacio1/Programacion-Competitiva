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
    
    int n,c,s;
    cin >> n >> c >> s;
    int pos=1;
    int ans=0;
    if(s==1)ans++;
    forn(i,c){
        //cout << pos << endl;
        int mov;
        cin >> mov;
        pos+=mov;
        if(pos==0)pos=n;
        if(pos==n+1)pos=1;

        if(pos==s)ans++;
    }
    cout << ans << endl;
    
    return 0;
}