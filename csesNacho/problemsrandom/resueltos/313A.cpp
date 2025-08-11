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
    tt=1;
    while(tt--){
        ll n;
        cin >> n;
        if(n<0){
            string nn = to_string(n);
            string a,b;
            forn(i,nn.size()){
                if(i!=nn.size()-2)a+=nn[i];
                if(i!=nn.size()-1)b+=nn[i];
            }
                
            cout << max(stoi(a),stoi(b)) << endl;
        }else{
            cout << n << endl;
        }
    }

    return 0;
}