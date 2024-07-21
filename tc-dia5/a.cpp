#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);

    int n,m;

    cin >> n >> m;

    forn(i,m){
        int l, r;
        cin >> l >> r;
    }

    forn(i,n){
        if(i%2==0){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << endl;
}