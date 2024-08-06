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
        string s;
        cin >> s;

        int repetida=0;
        char anterior = s[0];
        for(int i=1; i<s.size();i++){
            if(anterior==s[i]){
                repetida = i;
            }

            anterior=s[i];
        }
        //cout << repetida << endl;
        if(repetida==0){
            if(s[0]=='a'){
                cout << 'z';
                cout << s[0];
            }else{
                cout << 'a';
                cout << s[0];
            }
        }else{
            cout << s[0];
        }
        for(int i=1; i<s.size();i++){
           
            if(repetida==i){
                if(s[i-1]=='a'){
                cout << 'z';
                cout << s[i];
                }else{
                    cout << 'a';
                    cout << s[i];
                }
            }else{
                cout << s[i];
            }
            
        }
        cout << endl;
       
        
    }
    return 0;
}
