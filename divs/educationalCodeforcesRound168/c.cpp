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
        int n;
        string s;
        cin >> n;
        cin >> s;
        
        int abierto=0,cerrado=0;

        forn(i,s.size()){
            if(s[i]=='('){
                abierto++;
            }

            if(s[i]==')'){
                cerrado++;
            }
        }
        int puedoCerrar=0;
        forn(i,s.size()){
            if(s[i]=='_' && puedoCerrar>0){
                s[i]=')';
                puedoCerrar--;
                continue;
            }
            if(s[i]=='_' && puedoCerrar<=0){
                s[i]='(';
                puedoCerrar++;
                continue;
            }

            if(s[i]=='('){
                puedoCerrar++;
            }else{
                puedoCerrar--;
            }
        }
        int sum=0;
        forn(i,s.size()){
            if(s[i]=='('){
                sum+= -(i+1);
            }else{
                sum+= (i+1);
            }
           // cout << sum  <<" ";
        }
        cout << sum << endl;
    }
    return 0;
}
