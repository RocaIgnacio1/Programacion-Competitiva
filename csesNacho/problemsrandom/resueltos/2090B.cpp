#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
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
    cin >> tt;
    while(tt--){
        int n,m;
        cin >> n >> m;
        vector<string> grid;
        forn(i,n){
            string s;
            cin >> s;
            grid.push_back(s);
        }
        bool ans=true;
        forn(i,n){
            forn(j,m){
                if(grid[i][j]=='0')continue;
                bool arriba=false, izquierda=false;
                int p=i;
                while(p>=0){
                    if(grid[p][j]=='0')arriba=true;
                    p--;
                }
                p=j;
                while(p>=0){
                    if(grid[i][p]=='0')izquierda=true;
                    p--;
                }
                if(arriba&&izquierda)ans=false;
            }
        }
        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}