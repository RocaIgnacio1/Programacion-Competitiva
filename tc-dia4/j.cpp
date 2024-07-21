#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;

    ll WsTotal = 0;
    bool findV = false;
    forn(i, s.size()){
        if(s[i] == 'v'){
            WsTotal++;
            findV = true;
        }
        if (s[i] != 'v'){
            if (findV){
                WsTotal--;
                findV = false;
            }
        }
    }
    if (s[s.size()-1] != 'o'){
        WsTotal --;
    }

    ll Ws = 0;
    ll res = 0;
    findV = false;
    forn(i, s.size()){
        if(s[i] == 'v'){
            Ws++;
            findV = true;
        }
       
        if (s[i] != 'v'){
            if (findV == true){
                Ws--;
                findV = false;
            }
            res += (Ws * (WsTotal-Ws));
        }
    }
    cout << res << endl;
}