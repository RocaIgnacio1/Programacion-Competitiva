#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;

    forn(c, t){
        int n; cin >> n;
        int ans[2*n];
        bool found[2*n+1];
        memset(found, false, sizeof(found));

        forn(i, n){
            int g;
            forn(j, n){
                cin >> g;
                if (i == 0){
                    ans[j+1] = g;
                    found[g] = 1;
                }
            }
            if (i > 0) { // the last column
                ans[n+i] = g;
                found[g] = 1;
            }
        }

        forr(i, 1, 2*n+1){
            if (!found[i]) {
                ans[0] = i;
            }
        }
        forn(i, 2*n){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
