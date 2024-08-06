#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    
    forn(w,t){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int conA=0,conB=0,conC=0,conD=0;
        forn(i,n*4){
            if(s[i]=='A') conA++;
            if(s[i]=='B') conB++;
            if(s[i]=='C') conC++;
            if(s[i]=='D') conD++;
            
        }
        if(conA>n) conA=n;
        if(conB>n) conB=n;
        if(conC>n) conC=n;
        if(conD>n) conD=n;
        cout << conA+conB+conC+conD << endl;
    }
}