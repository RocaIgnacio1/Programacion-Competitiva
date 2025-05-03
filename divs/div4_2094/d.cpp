#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;

    forn(c, t){
        string s, p;
        cin >> p;
        cin >> s;

        if (s.size() < p.size()){ // |s| >= |p|
            cout << "NO\n";
        }

        int i = 0;
        bool valid = true;
        forn(j, s.size()){
            int n = 1, m = 1;
            while(p[i] == p[i+1]){
                i++;
                n++;
            }
            while(s[j] == s[j+1]){
                j++;
                m++;
            }

            if (m < n || m > 2*n || p[i] != s[j]) {
                valid = false;
                break;
            }

            /*cout << n << p[i] << endl;*/
            /*cout << m << s[j] << endl;*/
            i++;

            if (i > p.size()){ // p have the '\0' terminator
                cout << "i >= p.size()" << endl;
                valid = false;
                break;
            }
        }
        if (valid && i < p.size()) {
            valid = false;
        }
        cout << (valid ? "YES" : "NO") << '\n';
    }
}
