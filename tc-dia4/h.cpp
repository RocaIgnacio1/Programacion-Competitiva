#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    forn(i , t){
        string s;
        cin >> s;
        if(s[0] != s[s.size()-1]){
            s[s.size()-1] = s[0];
        }
        cout << s << endl;
    }
}