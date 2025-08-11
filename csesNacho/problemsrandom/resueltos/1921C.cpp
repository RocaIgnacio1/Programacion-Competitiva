#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        ll f,a,b;
        cin >> n >> f >> a >> b;
        vector<ll> times(n+1);
        times[0]=0;
        fora(1,i,n+1){
            cin >> times[i];
        }
        bool ans=true;
        //forn(i,times.size())cout<<times[i]<< " ";
        
        forn(i,n){
            if((times[i+1]-times[i])*a < b ){
                f-=((times[i+1]-times[i])*a);
            }else{
                f-=b;
            }
            if(f<=0){
                ans=false;
                break;
            }
        }
        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}