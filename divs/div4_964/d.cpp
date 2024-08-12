#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    
    forn(w,t){
        string s,p;
        cin >> s;
        cin >> p;
        int i=0;
        forn(j,s.size()){
            if(s[j]==p[i]){
                i++;
            }else{
                if(s[j]=='?' && (i<=p.size()-1)){
                    s[j]=p[i];
                    i++;
                }
            }

            if((i>p.size()-1) && s[j]=='?'){
                s[j]='a';
            }
           
        }
        if(i>=(p.size())){
            cout << "YES" << endl;
            cout << s << endl;
        
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
