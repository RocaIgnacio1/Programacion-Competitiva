#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

bool vis[1002][1002];
char tab[1002][1002];
int X, Y;
ll acum = 0;

void dfs(int x, int y){
    if(vis[x][y]) return;
    char c = tab[x][y];
    //cout << c << " " << x << " " << y << ": " << acum << endl;
    vis[x][y] = true;
    if(tab[x][y] == '#') return;
    if(tab[x][y] != '.' && tab[x][y] != 'S') acum+= (c-'0');
    if(x>0 && tab[x-1][y] == 'T') return;
    if(x<X-1 && tab[x+1][y] == 'T') return;
    if(y>0 && tab[x][y-1] == 'T') return;
    if(y<Y-1 && tab[x][y+1] == 'T') return;

    if(x>0) dfs(x-1,y);
    if(x<X-1) dfs(x+1,y);
    if(y>0) dfs(x,y-1);
    if(y<Y-1) dfs(x,y+1);
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("k.txt", "r", stdin);
    #endif

    int sx, sy;
    while(cin >> X >> Y){
        //cout << X << " " << Y << endl;
        forn(i, X){
            forn(j, Y){
                char k;
                cin >> k;
                acum =0;
                vis[i][j] = false;
                tab[i][j] = k;
                if(k == 'S'){
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(sx, sy);
        cout << acum << endl;
    }
    
    return 0;
}