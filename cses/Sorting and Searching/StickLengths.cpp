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
    ll sum=0;
    forn(i,n){
        cin >> p[i];
        sum+=p[i];
    }

    sort(p.begin(),p.end());
    ll op1 = p[n/2];
    ll op2 = p[(n/2)+1];
    ll ans1=0,ans2=0;
    forn(i,n){
        ans1 += abs(op1-p[i]);
        ans2 += abs(op2-p[i]);
    }
    cout << min(ans1,ans2) << endl;
    
}