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
    
    int tt;
    tt=1;
    while(tt--){
        int n; cin >> n;
        string s;
        cin >> s;
        int ans=0, p=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'){
                p++;
            }else{
                if(p>=2)ans+= p;
                p=0;
            }
        }
        if(p>=2)ans+= p;
        cout << ans << endl;
    }

    return 0;
}