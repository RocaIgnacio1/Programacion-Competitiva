#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        int a1, l1, a2, l2, a3, l3;
        cin >> a1 >> l1 >> a2 >> l2 >> a3 >> l3;
        bool ans=false;
        if(a1==a2+a3 && l2==l3 && a1==l1+l3)ans=true;
        if(a2==a1+a3 && l1==l3 && a2==l2+l3)ans=true;
        if(a3==a1+a2 && l1==l2 && a3==l3+l2)ans=true;
        if(l1==l2+l3 && a2==a3 && l1==a1+a3)ans=true;
        if(l2==l1+l3 && a1==a3 && l2==a2+a3)ans=true;
        if(l3==l1+l2 && a1==a2 && l3==a3+a1)ans=true;
        if(l1==l2 && l2==l3 && l1==a1+a2+a3)ans=true;
        if(a1==a2 && a2==a3 && a1==l1+l2+l3)ans=true;

        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}