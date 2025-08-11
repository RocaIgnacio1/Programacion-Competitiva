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

int main() {
    #ifdef EBUG
        //freopen("in1.txt", "r", stdin);
    #endif

    ll a=1, b=1000000000, mid=(a+b)/2, ans=0;
    //1000000000
    while(a<=b){
        string rta;
        cout << "? " << mid << endl;
        cin >> rta;
        if(rta=="YES"){
            a=mid+1;
        }else{
            ans=mid;
            b=mid-1;
        }
        mid=(a+b)/2;
    }
 
    cout << "! " << ans << endl;

    return 0;
}