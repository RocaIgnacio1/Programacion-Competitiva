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
        int z=0, k=0, ban=1;
        vector<vector<char>> grid(8);
        forn(i,8){
            forn(j,8){
                char val;
                cin >> val;
                grid[i].push_back(val);
                if(ban && val!='.'){
                    z=i;
                    k=j;
                    ban=0;
                }
            }
        }
        while(true){
            if(z>7 || grid[z][k]=='.' )break;
            cout << grid[z][k];
            z++;
        }
        cout<<endl;
    }

    return 0;
}