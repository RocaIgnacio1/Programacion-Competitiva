#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int n, m;
vector<vector<char>> grid;

bool okT(int i, int j){
    if(j-1<0 || j+1>=m || i-4<0){
        return false;
    }else{
        if(grid[i-4][j+1]=='#' && grid[i-4][j-1]=='#' &&
            grid[i][j]=='#' && grid[i-1][j]=='#' && grid[i-2][j]=='#' &&
            grid[i-3][j]=='#' && grid[i-4][j]=='#'
        
        ){
            grid[i][j]='.';
            grid[i-1][j]='.';
            grid[i-2][j]='.';
            grid[i-3][j]='.';
            grid[i-4][j]='.';

            grid[i-4][j+1]='.';
            grid[i-4][j-1]='.';

            return true;
        }else{
            return false;
        }
    }
}

bool okA(int i, int j){
    if(j-2<0 || i-4<0){
        return false;
    }else{
        if(grid[i][j]=='#' && grid[i-1][j]=='#' && grid[i-2][j]=='#' && 
            grid[i-3][j]=='#' && grid[i-4][j]=='#' && 
            grid[i-2][j-1]=='#' && grid[i-4][j-1]=='#' && 
            grid[i][j-2]=='#' && grid[i-1][j-2]=='#' && grid[i-2][j-2]=='#' && 
            grid[i-3][j-2]=='#' && grid[i-4][j-2]=='#' && grid[i-3][j-1]=='.'
        ){
                
            grid[i][j]='.';
            grid[i-1][j]='.';
            grid[i-2][j]='.';
            grid[i-3][j]='.';
            grid[i-4][j]='.';
            
            grid[i-2][j-1]='.';
            grid[i-4][j-1]='.';

            grid[i][j-2]='.';
            grid[i-1][j-2]='.';
            grid[i-2][j-2]='.';
            grid[i-3][j-2]='.';
            grid[i-4][j-2]='.';
          
            return true;
        }else{
            return false;
        }
    }
}

bool okP(int i, int j){
    if(j+2>=m || i-4<0 ){
        return false;
    }else{
        if(grid[i][j]=='#' && grid[i-1][j]=='#' && grid[i-2][j]=='#' && 
            grid[i-3][j]=='#' && grid[i-4][j]=='#' && 
            grid[i-2][j+2]=='#' && grid[i-3][j+2]=='#' && grid[i-4][j+2]=='#' && 
            grid[i-2][j+1]=='#' && grid[i-4][j+1]=='#' && grid[i-3][j+1]=='.'
        ){
                
            grid[i][j]='.';
            grid[i-1][j]='.';
            grid[i-2][j]='.';
            grid[i-3][j]='.';
            grid[i-4][j]='.';
            
            grid[i-2][j+2]='.';
            grid[i-3][j+2]='.';
            grid[i-4][j+2]='.';

            grid[i-2][j+1]='.';
            grid[i-4][j+1]='.';

            return true;
        }else{
            return false;
        }
    }
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    forn(i,n){
        vector<char> aux(m);
        forn(j,m){
            cin >> aux[j];
        }
        grid.push_back(aux);
    }
    int t=0, a=0, p=0;
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(grid[i][j]=='.')continue;
            if (okP(i,j)) p++;
            if (okA(i,j)) a++;
            if (okT(i,j)) t++;
            /*
            forn(k,n){
                forn(z,m){
                    cout<<grid[k][z];
                }
                cout<<endl;
            }
            cout<<endl;
            */
        }
    }
    cout << t << " " << a << " " << p << endl;

    return 0;
}