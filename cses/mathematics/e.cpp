#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll inf = 1e18+100;
const ll mod = 1e9+7;
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
 
#ifdef EBUG
#else
#endif
 
 
int gcd(int a, int b){
    if(b== 0) return a;
    return gcd(b, a%b);
}
 
unordered_map<int, int> s;
int divisors(int n){
    int res = 0;
    for(int i = 1; i*i <= n; i++){
        int a;
        if(n%i == 0){
            if(i*i==n){
                    s[i]++;
            }else{
                s[i]++;
                s[n/i]++;
            }
        }
    }
    return res;
}
 
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    forn(i, n){
        int p;
        cin >> p;
        divisors(p);
    }
    int ret;
    for(auto i: s){
        if(i.second >= 2) ret = max(ret, i.first);
    }
    cout << ret << '\n';
    return 0;
}