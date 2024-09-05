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

    int n;
    cin >> n;
    vector<ll> p(n);
    forn(i,n){
        cin >> p[i];
    }

    //acumulado
    // entrante
    // si el entrante es negativo y su abs es mayor o igual al acumulado
    ll acumulado=-INF, ans=-INF;
    bool ban=false;
    forn(i,n){
        if(ban)break;
        acumulado=p[i];
        ans=max(ans,acumulado);
        if(p[i]<0 && p[i+1]>=p[i])continue;
        for(int j=i+1;j<n;j++){
            if(j==n-1)ban=true;
            if(p[j]<0 && abs(p[j])>=acumulado){
                break;
            }
            acumulado+=p[j];
            ans=max(ans,acumulado);
        }
        ans=max(ans,acumulado);
    }
    cout << ans << endl;
    
}