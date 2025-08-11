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
    
    int n,q;
    cin >> n >> q;
    int m[n][n], sum=0;
    forn(i,n){
        forn(j,n){
            char a;int s=0;
            cin >> a;
            if(a=='*')s=1;
            m[i][j] = s;
            if (i > 0) m[i][j] += m[i-1][j];
            if (j > 0) m[i][j] += m[i][j-1];
            if (i > 0 && j > 0) m[i][j] -= m[i-1][j-1];

        }
    }
    
    forn(i,q){
        int x1,y1,x2,y2,a=0,b=0,c=0,d=0;
        cin >> x1 >> y1 >> x2 >> y2;    
        x1--;y1--;x2--;y2--;
        a = m[x2][y2];
        if(y1>0)b=m[x2][y1-1];
        if(x1>0)c=m[x1-1][y2];
        if(x1>0 && y1>0)d=m[x1-1][y1-1];
        cout << a-b-c+d << endl;

    }
   
    

    return 0;
}