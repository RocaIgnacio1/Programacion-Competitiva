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
    
    int tt;
    cin>>tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n);
        forn(i,n){
            forn(j,m){
                ll val;
                cin >> val;
                a[i].push_back(val);
            }
        }
        /*
        if(n==1 && m==1){

        }
        */
   
        map<pair<int,int>,ll> arriba;
        int i=0,j=m-1;
        while(i<=(n-1) && j>=0){
            
            int ii=i, jj=j;
            ll suma=0;
            while(ii<n && jj<m){
                suma+=a[ii][jj];
                ii++;
                jj++;
            }
            arriba[make_pair(i,j)]=suma;
            
            if(j>=1){
                j--;
            }else{
                i++;
            }
            
        }
        map<pair<int,int>,ll> abajo;
        i=n-1,j=m-1;
        while(i>=0 && j>=0){
            
            int ii=i, jj=j;
            ll suma=0;
            while(ii>=0 && jj<m){
                suma+=a[ii][jj];
                ii--;
                jj++;
            }
            abajo[make_pair(i,j)]=suma;
            
            if(j>=1){
                j--;
            }else{
                i--;
            }
            
        }
        /*
        for(auto i: abajo){
            cout << i.first.first << " " << i.first.second << " " <<  i.second << endl;
        }
        for(auto i: arriba){
            cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        }
        */
        ll ans=0;
        forn(i,n){
            forn(j,m){
                int aa = min(abs(i-(n-1)), j);
                int bb = min(i,j);
                ll valor1 = abajo[make_pair( i+aa, j-aa )];
                ll valor2 = arriba[make_pair( i-bb , j-bb)];
                ans = max(ans,(valor1+valor2-a[i][j]));
            }
        }
        cout << ans << endl;
    }

    return 0;
}