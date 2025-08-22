#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
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
    
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n),b;
        ll maximo = 0, num;
        forn(i,n){
            cin >> a[i];
            maximo = max(maximo,a[i]);
            if(i+1==k)num=a[i];
        }
        sort(a.begin(),a.end());
        
        int indice=0,j=1;
        b.push_back(a[0]);
        forr(i,1,n){
            if(a[i]!=a[i-1]){
                b.push_back(a[i]);
                if(b[j]==num)indice=j;
                j++;
            }
        }

        bool ans=true;
        ll agua=0;
        forr(i,indice,b.size()-1){
            if(agua+abs(b[i]-b[i+1])>b[i]){
                ans=false;
                break;
            }else{
                agua+=abs(b[i]-b[i+1]);
            }
        }
        
        if(ans) cout << "YES" << endl;
        else cout << "NO" <<  endl;
        
    }

    return 0;
}