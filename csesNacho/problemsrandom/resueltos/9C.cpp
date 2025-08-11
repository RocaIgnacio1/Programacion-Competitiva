#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

vector<ll> numeros;

void formar_numeros(int pos, string n){
    if(pos==10)numeros.push_back(stoi(n));
    else{
        formar_numeros(pos+1, "1"+n);
        formar_numeros(pos+1, "0"+n);    
    }
}

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
        formar_numeros(0,"");
        ll ans=0;
        forn(i,numeros.size()){
            if(numeros[i]<=n && numeros[i]!=0){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
