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
    
    int tt; cin>>tt;
    while(tt--){
        int n; cin >> n;
        string s; cin >> s;
        int ceros=0;
        forn(i,n){
            if(s[i]=='0')ceros++;
        }
        reverse(s.begin(),s.end());
        deque<int> pos;
        forn(i,n){
            if(s[i]=='0')pos.push_back(i);
        }
        ll ans=0;
        for(int i=0; i<n; i++){
            if(ceros>=(i+1)){
                ans += pos.front()-i;
                pos.pop_front();
                cout << ans << " ";
            }else{
                cout << -1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}