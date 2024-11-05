#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

set<int> divisors(int n){
    set<int> res;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            res.insert(i);
            if(i*i != n){
                res.insert(n/i);
            }
        }
    }
    return res;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    while(t--){
        int w, l;
        cin >> w >> l;

        set<int> ans = {1, 2};
        set<int> divs;
        
        divs = divisors(gcd(l, w-2));
        for (int a : divs){
            ans.insert(a);
        }

        divs = divisors(gcd(l-1, w-1));
        for (int a : divs){
            ans.insert(a);
        }
        
        divs = divisors(gcd(l-2, w));
        for (int a : divs){
            ans.insert(a);
        }

        cout << ans.size() << " ";
        for (int a : ans){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}