#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    int t;
    cin >> t;
    forn(j, t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string aux, aux1;
        aux.push_back(s[0]);
        aux1.push_back(s[0]);

        int con = 0;
        bool ban = true, ban2 = true;
        fora(1,i,n){
            if(s[i-1] >= s[i] && ban2){
                aux1.push_back(s[i]);
            }else{
                ban2 = false;
            }

            if(s[i-1] > s[i] && ban){
                aux.push_back(s[i]);
            }else{
                ban = false;
            }
        }
        string res1, res2;
        forn(i, aux.size()){
            res1.push_back(aux[i]);
        }
        fori(i, aux.size()){
            res1.push_back(aux[i]);
        }
        forn(i, aux1.size()){
            res2.push_back(aux1[i]);
        }
        fori(i, aux1.size()){
            res2.push_back(aux1[i]);
        }
        cout << min(res1, res2) << endl;
    }
}