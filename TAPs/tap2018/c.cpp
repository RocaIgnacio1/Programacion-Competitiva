#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int solve(int n){
    if(n == 1) return 4;
    if(n == 2) return 6;
    if(n == 3) return 2;
    if(n == 4) return 4;
    if(n == 5) return 8;
    n-=6;
    if(n%8==0) return 3;
    if(n%8==1) return 2;
    if(n%8==2) return 6;
    if(n%8==3) return 1;
    if(n%8==4) return 2;
    if(n%8==5) return 2;
    if(n%8==6) return 4;
    if(n%8==7) return 8;
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a) << solve(b) << solve(c) << solve(d) << endl;
    
}