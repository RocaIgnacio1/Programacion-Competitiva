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
    t=1;
    while(t--){
        string s, a = "abcdefghijklmnopqrstuvwxyz";
        cin>>s;
        map<char,int> pos;
        forn(i,a.size()){
            pos[a[i]]=i;
        }
        int ans=0;
        char actual='a';
        forn(i,s.size()){
            ans += min(abs(pos[actual]-pos[s[i]]), min(pos[actual],pos[s[i]])+26-max(pos[actual],pos[s[i]]));
            actual = s[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}