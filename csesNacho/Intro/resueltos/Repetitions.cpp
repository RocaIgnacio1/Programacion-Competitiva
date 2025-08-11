#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

#define operacion(x, y) (x+y)
#define neutro 0
#define tipo ll



int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   
    string s;
    cin >> s;
    int suma=0,ans=0;
    forn(i,s.size()){
        if(i==0)suma++;
        else{
            if(s[i]==s[i-1])suma++;
            else suma=1;
        }
        ans = max(ans,suma);
    }
    cout << ans << endl;

    return 0;
}