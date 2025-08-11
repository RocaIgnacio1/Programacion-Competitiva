#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int buscar(int n, int m){
    if(n==m)return 1;
    if(n%3!=0)return 0;
    if(n<m)return 0;
    
    return buscar(n/3,m)+buscar((n/3)*2,m);
    
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin>>tt;
    while(tt--){
        int n,m, ans=0;
        cin >> n >> m;
        if(buscar(n,m)>0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}