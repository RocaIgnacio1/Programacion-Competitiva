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
        string s;
        cin >> s;
        int mayus=0;
        if(s.size()==1){
            if(s[0]!=(char) tolower(s[0])){
                cout << (char) tolower(s[0]) << endl;
            }else{
                cout << (char) toupper(s[0]) << endl;
            }
            continue;
        }
        forn(i,s.size()){
            if(i!=0){
                if(s[i]!=(char) tolower(s[i]))mayus++;
            }
        }
        if(mayus!=s.size()-1){
            cout<<s;
        }else{
            forn(i,s.size()){
                if(i==0){
                    if(s[i]!=(char) tolower(s[i])){
                        cout << (char) tolower(s[i]);
                    }else{
                        cout << (char) toupper(s[i]);
                    }
                }else{
                    cout << (char) tolower(s[i]);
                }
            }
        }
        cout<<endl;
    }

    return 0;
}