
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main() {
    freopen("input.txt", "r", stdin);
    int n, x, y,t;
    cin >> t;
    forn(w,t){

    
        cin >> n >> x >> y;
        int a[n];

        forn(i,n){
            a[i]=1;
        }

        if(x==n)a[x-2]=-1;
        else a[x-1]=-1;
        
        forn(i,y){
            if(a[i]==1)a[i]=-1;
            else a[i]=1;
        }
        forn(i,n){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
