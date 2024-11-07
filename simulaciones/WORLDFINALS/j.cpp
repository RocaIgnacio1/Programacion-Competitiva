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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> m;
    forn(i, n){
        char a;
        cin >> a;
        int p;
        cin >> p;
        if(a == 'C'){  
            forn(i, p){
                int x;
                cin >> x;
                m[x]++;
            }
        }
        if(a == 'J'){
            unordered_map<int, int> v, r;
            int x;
            cin >> x;
            forn(i, p){
                int p;
                v[p]++;
            }
            bool ban = true;
            for(auto i: v){
                if(m.count(i.first) < i.second){
                    ban = false;
                }
            }

        }
    }
}