#include<bits/stdc++.h>
#include <ostream>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    string aux;
    getline(cin, aux);
    forn(i, t) {
        string s, ans;
        getline(cin, s);
        bool new_word = true;
        /*cout << s << endl;*/
        for(char c : s){
            if (new_word and c != ' ') {
                ans.push_back(c);
                new_word = false;
            }

            if (c == ' '){
                new_word = true;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
