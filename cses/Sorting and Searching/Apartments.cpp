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

    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> deseo(n);
    vector<ll> dep(m);
    forn(i,n){
        cin >> deseo[i];
    }
    forn(i,m){
        cin >> dep[i];
    }
    
    sort(deseo.begin(),deseo.end());
    sort(dep.begin(),dep.end());
    int w=0,ans=0;
    forn(i,n){
        if(w>=dep.size())break;
        if(deseo[i]>=dep[w]-k && deseo[i]<=dep[w]+k){
            w++;
            ans++;
        }else{
            if(deseo[i]>dep[w]+k){
                i--;
                w++;
            }
        }
    }
    cout << ans << endl;
}