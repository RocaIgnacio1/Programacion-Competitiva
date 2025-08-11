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
    cin>>t;
    while(t--){
        string s,p,ans="";
        cin >> s >> p;
        map<char,int> letras;
        forn(i,p.size()){
            letras[p[i]]++;
        }
        for(int i=s.size()-1; i>=0; i--){
            if(letras.find(s[i])!=letras.end()){
                ans+=s[i];
                letras[s[i]]--;
                if(letras[s[i]]<=0)letras.erase(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        if(p==ans)cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}