#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)
#define ll long long
#define fora(k, i, n) for(int i = k; i < n; i++)

#ifdef EBUG
//local
#else
//judge
#endif

ll forrn(int b, int a){
    if(a > b){
        return a - b;
    }
    return 3*(b-a);
}



int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    forn(k, t){
        vector<int>v;
        int n;
        cin >> n;
        forn(i, n){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }
        reverse(v.begin(), v.end());
        vector<ll>dp1, dp2;
        dp1.push_back(0);
        dp2.push_back(0);
        dp2.push_back(0);
        dp1.push_back(forrn(v[0], v[1]));
        fora(2, i, n){
            ll a = forrn(v[i-1], v[i])+dp2[i-1];
            dp1.push_back(a);
            dp2.push_back(min(a,min(dp1[i-1], dp1[i-2])));
        }

        cout << min(dp2[n-1], dp1[n-1]) << endl;


    }
}
