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
    
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin >> n >> m;
        string s,t;
        cin >> s >> t;
        for(int i=0; i<=5; i++){
            if(s.find(t) != string::npos){
                cout << i << endl;
                break;
            }
            s+=s;
            if(i==5){
                cout << -1 << endl;
            }
        }
    }

    return 0;
}