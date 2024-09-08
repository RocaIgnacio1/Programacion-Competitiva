#include <bits/stdc++.h>
using namespace std;
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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int c1, c2, b1, b2, p1, p2;
    cin >> c1 >> b1 >> p1;
    cin >> c2 >> b2 >> p2;
    int res = 0;
    if(c2>c1) res += c2-c1;
    if(b2>b1) res += b2-b1;
    if(p2>p1) res += p2-p1;
    cout << res << endl;
     
    return 0;
}