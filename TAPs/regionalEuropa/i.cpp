#include <bits/stdc++.h>
using namespace std;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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

#define MAXN 200000

struct RMQmax{
    int sz;
    pair<int, int> t[4*MAXN];
    pair<int, int> &operator[](int p){return t[sz+p];}
    void init(int n){//O(nlgn)
        sz = 1 << (32-__builtin_clz(n));
        forn(i, 2*sz) t[i] = make_pair(-1, 0);
    }
    void updall(){
        dforn(i, sz) t[i] = max(t[2*i], t[2*i+1]);
    }
    pair<int, int> get(int i, int j){return get(i, j, 1, 0, sz);}
    pair<int, int> get(int i, int j, int n, int a, int b){
        if(j<=a || i>= b) return make_pair(-1, 0);
        if(i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return max(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, pair<int, int> val){
        for(p+=sz; p>0 && t[p] != val;){
            t[p]=val;
            p/=2;
            val = max(t[2*p], t[2*p+1]);
        }
    }
}mx;

struct RMQmin{
    int sz;
    pair<int, int> t[4*MAXN];
    pair<int, int> &operator[](int p){return t[sz+p];}
    void init(int n){//O(nlgn)
        sz = 1 << (32-__builtin_clz(n));
        forn(i, 2*sz) t[i] = make_pair(1e9, 0);
    }
    void updall(){
        dforn(i, sz)t[i] = min(t[2*i], t[2*i+1]);
    }
    pair<int, int> get(int i, int j){return get(i, j, 1, 0, sz);}
    pair<int, int> get(int i, int j, int n, int a, int b){
        if(j<=a || i>= b) return make_pair(1e9, 0);
        if(i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return min(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, pair<int, int> val){
        for(p+=sz; p>0 && t[p] != val;){
            t[p]=val;
            p/=2;
            val = min(t[2*p], t[2*p+1]);
        }
    }
}mn;


void solve(int pos, vector<pair<int, int>> &ran, map<int, int> &dp){
    dp[pos] = 0;
    pair<int, int> firs;
    queue<int> q;
    q.push(pos);
    mn.set(pos, make_pair(1e9, 0));
    mx.set(pos, make_pair(-1, 0));
    while(!q.empty()){
        int p = q.front();
        q.pop();
        firs = mn.get(p+1, ran[p].second+1);
        while(firs.first <= p && dp.count(firs.second) == 0){
            dp[firs.second] = dp[p] + 1;
            q.push(firs.second);
            mn.set(firs.second, make_pair(1e9, 0));
            mx.set(firs.second, make_pair(-1, 0));
            firs = mn.get(p+1, ran[p].second+1);
        }
        firs = mx.get(ran[p].first, p);
        while(firs.first >= p && dp.count(firs.second) == 0){
            dp[firs.second] = dp[p] + 1;
            q.push(firs.second);
            mn.set(firs.second, make_pair(1e9, 0));
            mx.set(firs.second, make_pair(-1, 0));
            firs = mx.get(ran[p].first, p);
        }
    }
}

//array<pair<int, int>, 4*4*100000> lks;
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int tr;
    cin >> tr;
    forn(i, tr){
        map<int, int> dp;
        vector<pair<int, int>> ran;
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> dis;
        forn(j, n){
            int r;
            cin >> r;
            dis.push_back(r);
            int a1, a2;
            a1 = j - r;
            a2 = j + r;
            if(a1 < 0) a1 = 0;
            if(a2 >= n) a2 = n-1;
            ran.push_back(make_pair(a1, a2));
        }
        mn.init(n); forn(i, n) mn[i] = make_pair(ran[i].first, i); mn.updall();
        mx.init(n); forn(i, n) mx[i] = make_pair(ran[i].second, i); mx.updall();
        /* fora(1, j, 2*mn.sz){
            cout <<"(" <<  mn.t[j].first << ", " << mn.t[j].second <<  ") ";
            if(j == 1 || j == 3 || j == 7 || j == 15) cout << endl;
        } */
        solve(a-1, ran, dp);
        /* forn(i, n){
            cout << dp[i] << " ";
        }cout << endl; */
        cout << dp[b-1] << "\n";
    }

}