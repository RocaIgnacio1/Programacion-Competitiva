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
 
#define MAXN 800000
#define operacion(x, y) x + y
#define neutro 0
#define tipo ll
 
struct RMQ{
    int sz;
    tipo t[4*MAXN];
    tipo &operator[](int p){return t[sz+p];}
    void init(int n){//O(nlgn)
        sz = 1 << (32-__builtin_clz(n));
        forn(i, 2*sz) t[i] = neutro;
    }
    void updall(){
        dforn(i, sz) t[i] = operacion(t[2*i], t[2*i+1]);
    }
    tipo get(int i, int j){return get(i, j, 1, 0, sz);}
    tipo get(int i, int j, int n, int a, int b){
        if(j<=a || i>= b) return neutro;
        if(i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }
    void set(int p, tipo val){
        for(p+=sz; p>0 && t[p] != val;){
            t[p]=val;
            p/=2;
            val = operacion(t[2*p],t[2*p+1]);
        }
    }
}sm;
 
#include <bits/stdc++.h>
using namespace std;
 
int bs(vector<int> &v, int val){
    int l = 0, r = v.size() - 1, mid = (l+r)/2;
    while(l <= r){
        if(val < v[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
        mid = (l+r)/2;
    }
    if(val < v[mid]){
        mid --;
    }
 
    return mid;
}
 
int main(){
        #ifdef EBUG
            freopen("input.txt", "r", stdin);
        #endif
        ios :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
 
        int n, q;
        cin >> n >> q;
        unordered_map<int, int> aux;
        vector<int> vals, arr, sueldo;
        vector<tuple<char, int, int>> querys;
        forn(i, n){
            int a;
            cin >> a;
            aux[a]++;
            sueldo.push_back(a);
        }
        forn(i, q){
            char s;
            int a, b;
            cin >> s >> a >> b;
            querys.push_back(make_tuple(s,a,b));
            if(s == '!'){
                aux[b]++;
                aux[b]--;
            } 
        }
        int con = 0;
        for(auto i: aux){
            vals.push_back(i.first);
            aux[i.first] = con;
            arr.push_back(i.second);
            con++;
        }
        /* for(auto i: aux){
            cout << i.first << " " << i.second << endl;
        } */
        ll x = arr[0];
        sm.init(arr.size()); forn(i, arr.size()) sm[i] = arr[i]; sm.updall();
        
        /* forn(i, arr.size()){
            cout << sm.get(i, i+1) << " ";
        }cout << endl; */
        for(auto i : querys){
            char s = get<0>(i);
            int e = get<1>(i);
            int v = get<2>(i);
            if(s == '!'){
                sm.set(aux[v], sm.get(aux[v], aux[v]+1) + 1);
                sm.set(aux[sueldo[e-1]], sm.get(aux[sueldo[e-1]], aux[sueldo[e-1]]+1) - 1);
                sueldo[e-1] = v;
            }else{
                bool ban = false;
                if(aux.count(e) == 0) ban = true;
                e = bs(vals, e);
                e += ban;
                v = bs(vals, v);
                cout << sm.get(0, v+1) - sm.get(0, e) << "\n";
            }
        }
 
        /* forn(i, arr.size()){
            cout << sm.get(i, i+1) << " ";
        }cout << endl; */
 
    return 0;
}