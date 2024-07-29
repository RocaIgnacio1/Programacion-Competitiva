#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    forn(w,t){
        int n,x;
        cin >> n >> x;
        int ans=0;
        for(int a=1; a<=n; a++){
            for(int b=1; a*b<=n; b++){
                for(int c=1; (a*b+a*c+b*c)<=n;c++){
                    if(a+b+c <= x) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
