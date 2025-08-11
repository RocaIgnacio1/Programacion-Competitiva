#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int n;
ll suma=0, ans=10000000000;
vector<ll> p;

void solve(int i, ll s){
    if(i==(n-1)){
        ans=min(ans, abs(abs(suma-s)-s));
    }else{
        solve(i+1 , s+p[i]);
        solve(i+1 , s);
    }
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    forn(i,n){
        ll a;
        cin>>a;
        p.push_back(a);
        suma+=p[i];
    }
    
    solve(0,0);
    cout<<ans<<endl;
    
    return 0;
}