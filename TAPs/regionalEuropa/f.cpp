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
   
    int t;
    cin >> t;
    forn(i, t){
        int n, m, maxr = 0, maxw = 0;
        cin >> n >> m;
        forn(j, m){
            int r, w;
            cin >> r >> w;
            maxr = max(maxr, r);
            maxw = max(maxw, w);
        }
        if(maxw + maxr <= n){
            forn(z, maxr){
                cout << 'R';
            }
            forn(z, n - maxr){
                cout << 'W';
            }
            cout << endl;
            
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
}