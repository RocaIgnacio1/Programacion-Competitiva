#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    int num = 0;
    int first = 1;
    int shift = 0;
    forn(i, n){
        forn(j, m){
            if (j == 0) {
                if (num == first) {
                    // shift
                    shift = (shift + 1) % k;
                    num = shift;
                }
                first = num;
            }
            cout << num+1 << ' ';
            num = (num + 1) % k;
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
