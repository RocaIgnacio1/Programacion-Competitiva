#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    forn(i, t){
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        if (m <= abs(l)) {
            cout << -m << " 0\n";
        }else{
            cout << l << ' ' << l+m << '\n'; 
        }
    }

    return 0;
}
