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
    forn(j,n){
        int x;cin>>x;
        vector<int> divisores;
        for(int i=1; (i*i)<=x; i++){
            if(x%i==0){
                divisores.push_back(x/i);
                if(i*i==x)continue;
                divisores.push_back(i);
            }
        }
        forn(i,divisores.size()){
            //cout<<divisores[i]<<" ";
        }
        cout<<divisores.size()<<endl;
    }    

    return 0;
}