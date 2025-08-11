#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000
const ll mod = 1000000007;


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>> n;
    vector<int> c(1000001);
    forn(i,1000001){
        c[i]=0;
    } 
    forn(i,n){
        int val;
        cin >> val;
        c[val]++;
    }

    for(int i=1000001; i>=1; i--){
        int multiplos=0;
        for(int j=i; j<=1000001; j+=i){
            multiplos+=c[j];
        }
        if(multiplos>=2){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}