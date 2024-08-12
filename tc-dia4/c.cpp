#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a;
    forn(i,n){
        int valor;
        cin >> valor;
        a.push_back(valor);
    }
    int ans=0;
    int maximo=a[0];
    forn(i,n){
        maximo=max(a[i],maximo);
        if(maximo<=(i+1)){
            ans++;
        }
    }

    cout << ans << endl;
}