#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif
char v[1010][1010];
int n,m;
void tapar(int x, int y){
    v[x][y] = 'X';
    if(x+1<n && v[x+1][y]=='O'){
        tapar(x+1, y);
    }
    if(y+1<m && v[x][y+1]=='O'){
        tapar(x, y+1);
    }
    if(y-1>=0 && v[x][y-1]=='O'){
        tapar(x, y-1);
    }
    if(x-1>=0 && v[x-1][y]=='O'){
        tapar(x-1, y);
    }
}

bool chequear(int x, int y){
    if(x+1 >= n || y+1 >= m) return false;
    if(v[x][y] == 'O' && v[x+1][y] == 'O' && v[x][y+1] == 'O' && v[x+1][y+1] == 'O'){
        tapar(x,y);
        return true;
    }
    return false;
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
        vector<char> aux;
        forn(j,m){
            char p;
            cin >> p;
            v[i][j] = p;
        }
    }
    int con = 0;
    forn(i,n){
        forn(j,m){
            cout << v[i][j];
            if(chequear(i,j)) con++;
        }
        cout << endl;
    }
    cout << con << endl;


    return 0;
}
