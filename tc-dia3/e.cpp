#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    freopen("input.txt", "r", stdin);
    int t,n;
    string s;

    cin >> t;

    forn(i,t){
        char s[50];

        bool m=false,w=false,e=false,o=false;
        cin >> n;
        forn(j,n){
            cin >> s[j];

            if((s[j]=='m' || s[j]=='M')){
                m=true;
            }
            if((s[j]=='m' || s[j]=='M') && (e==true || o==true || w==true)){
                m=false;
                break;
            }

            if((s[j]=='e' || s[j]=='E')){
                e=true;
            }
            if((s[j]=='e' || s[j]=='E') && (m==false || o==true || w==true)){
                e=false;
                break;
            }


            if((s[j]=='o' || s[j]=='O')){
                o=true;
            }
            if((s[j]=='o' || s[j]=='O') && (m==false || e==false || w==true)){
                o=false;
                break;
            }


            if((s[j]=='w' || s[j]=='W')){
                w=true;
            }
            if((s[j]=='w' || s[j]=='W') && (m==false || e==false || o==false)){
                w=false;
                break;
            }
            
            if((s[j]!='m' && s[j]!='M' && s[j]!='e' && s[j]!='E' && s[j]!='o' && s[j]!='O' && s[j]!='w' && s[j]!='W')){
                m=false;
                break;
            }
            
        }

        if(m && e && o && w){
            cout << "YES" << endl;
        }else{
             cout << "NO" << endl;
        }

    }
    return 0;
}