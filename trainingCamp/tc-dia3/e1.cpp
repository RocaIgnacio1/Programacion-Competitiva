#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    int t,n;

    cin >> t;

    forn(i,t){
        string s;
        cin >> n;
        forn(j,n){
            char r;
            cin >> r;
            bool aux = true;
            if(r == 'M'){
                s.push_back('m');
                aux = false;
            }
            if(r == 'E'){
                s.push_back('e');
                aux = false;
            }
            if(r == 'W'){
                s.push_back('w');
                aux = false;
            }
            if(r == 'O'){
                s.push_back('o');
                aux = false;
            }

            if(aux){
                s.push_back(r);
            }
        }
        string aux;
        forn(i, s.size() - 1){
            if(s[i]!=s[i+1]){
                aux.push_back(s[i]);
            }
        }
        aux.push_back(s[s.size() - 1]);
        if("meow" == aux){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        //cout << aux << endl;
    }
    return 0;
}