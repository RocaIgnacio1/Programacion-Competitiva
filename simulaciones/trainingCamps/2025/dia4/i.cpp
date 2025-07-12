#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int t; cin >> t;
    int initM = 0;
    while(t--){
        string w;
        int m, b;
        cin >> w;
        if (w == "ROUND"){
            cin >> m >> b;

            if(b < 0.3*m){
                cout << "PLAY\n";
            }else{
                cout << "SKIP\n";
            }
            cout.flush();
        }else{
            break;
        }
    }
 
    return 0;
}
