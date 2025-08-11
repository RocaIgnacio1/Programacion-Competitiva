#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
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

bool ask(int i, int j){
    string res;
    cout << "? " << i << " " << j << endl;
    cout.flush();
    cin >> res;
    return res=="YES";
}

int main() {
    #ifdef EBUG
        //freopen("in1.txt", "r", stdin);
    #endif
    ll n;
    cin >> n;
    cout << n << " ";
    while(n!=1){
        if(n%2==0){
            n= n/2;
        }else n=n*3+1;
        cout << n << " ";
    }
    cout << endl;
    return 0;
}