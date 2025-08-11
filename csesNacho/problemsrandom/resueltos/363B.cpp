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
    
    int t;
    t=1;
    while(t--){
        int n,k,s=0;
        cin >> n >> k;
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<=n; i++){
            int val; cin >> val;
            s+=val;
            prefix[i]=s;
        }
        int indice, minimo=INT_MAX;
        for(int i=1; i+k<=n+1; i++){
            if(prefix[i+k-1]-prefix[i-1] < minimo){
                minimo = prefix[i+k-1]-prefix[i-1];
                indice=i;
            }
        }
        cout << indice << endl;
    }

    return 0;
}