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
        int a1,a2,b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int ans=0;
        if(a1>b1){
            if(a2>=b2)ans++;
        }else{
            if(a1==b1 && a2>b2)ans++;
        }

        if(a1>b2){
            if(a2>=b1)ans++;
        }else{
            if(a1==b2 && a2>b1)ans++;
        }

        if(a2>b1){
            if(a1>=b2)ans++;
        }else{
            if(a2==b1 && a1>b2)ans++;
        }

        if(a2>b2){
            if(a1>=b1)ans++;
        }else{
            if(a2==b2 && a1>b1)ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
