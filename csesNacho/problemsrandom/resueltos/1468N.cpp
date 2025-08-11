#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
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
    
    int t;
    cin>>t;
    while(t--){
        ll c1,c2,c3,a1,a2,a3,a4,a5;
        cin >> c1 >> c2 >> c3;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;

        c1-=a1;
        c2-=a2;
        c3-=a3;
        if(c1<0||c2<0||c3<0){
            cout << "NO" << endl;
            continue;
        }

        a4 = max((ll) 0, (a4-c1));
        a5 = max((ll) 0, (a5-c2));

        c3-= (a4+a5);
        if(c3<0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;


    }

    return 0;
}