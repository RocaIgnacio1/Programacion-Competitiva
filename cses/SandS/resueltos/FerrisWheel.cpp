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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n,x;
    cin >> n >> x;
    vector<ll> p(n);
    forn(i,n){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int i=0, j= p.size()-1, ans=0;
    while(i<=j){
        
        if(i==j){
            if(p[i]<=x)ans++;
            break;
        }
        if(p[i]+p[j]<=x){
            ans++;
            i++;
            j--;
        }else{
            if(p[j]<=x)ans++;
            j--;
        }
    }
    cout << ans << endl;
}
