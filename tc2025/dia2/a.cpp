//https://codeforces.com/gym/102346/problem/G

#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i =(a);i<int(b); ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i =(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cerr << #v << " = " << (v) << "\n";
#define sz(v) (int((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define pp pop_back
#define fst first
#define snd second

using ll = long long;
using ull = unsigned ll;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vll = vector<ll>;

const ll MAXN = 110;
//const ll INF = 1e18 +100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


// Minima asignacion en O(n^3)
// Lado izquierdo [0..n), lado derecho [0..m). OJO: n <= m
typedef long double td; typedef vector<int> vi; typedef vector<td> vd;
const td INF = 1e100;	   // Para max asignacion, INF = 0, y negar costos
bool zero(td x) {return fabs(x) < 1e-9;}	// Para int/ll: return x==0;
struct Hungarian{
    vector<pii> ans;			//Guarda las aristas usadas en la asignacion (cada arista es [0..n)x[0..m))
    int n; vector<vd> cs; vi L, R;
	Hungarian(int N, int M) : n(max(N,M)), cs(n,vd(n)), L(n), R(n){
		forn(x, N) forn(y, M) cs[x][y] = INF;
	}
	void set(int x, int y, td c) { cs[x][y] = c; }
	td assign(){
		int mat = 0; vd ds(n), u(n), v(n); vi dad(n), sn(n);
		forn(i, n) u[i] = *min_element(all(cs[i]));
		forn(j, n){
			v[j] = cs[0][j]-u[0];
			forr(i, 1, n) v[j] = min(v[j], cs[i][j] - u[i]);
		}
		L = R = vi(n, -1);
		forn(i, n) forn(j, n) if(R[j] == -1 and zero(cs[i][j] - u[i] - v[j])){
			L[i] = j; R[j] = i; mat++; break;
		}
		for(; mat < n; mat ++){
			int s = 0, j = 0, i;
			while(L[s] != -1) s++;
			fill(all(dad), -1); fill(all(sn), 0);
			forn(k, n) ds[k] = cs[s][k]-u[s]-v[k];
			while(true){
				j = -1;
				forn(k, n) if(!sn[k] and (j == -1 or ds[k] < ds[j])) j = k;
				sn[j] = 1; i = R[j];
				if(i == -1) break;
				forn(k, n) if(!sn[k]){
					auto new_ds = ds[j] + cs[i][k] - u[i]-v[k];
					if(ds[k] > new_ds) ds[k]=new_ds, dad[k]=j;
				}
			}
			forn(k, n) if(k!=j and sn[k]) { auto w = ds[k]-ds[j]; v[k] += w, u[R[k]] -= w; }			
			u[s] += ds[j];
			while(dad[j] >= 0) { int d = dad[j]; R[j] = R[d]; L[R[j]] = j; j = d; }
			R[j] = s; L[s] = j;
		}
		td value = 0; forn(i, n) value += cs[i][L[i]], ans.pb({i, L[i]});
		return value;
	}
};

bool f(pii x, pii y){
    return x.snd < y.snd;
}

void solve(){
    int t;
    cin >> t;
    
    while(t--){          
        cerr << "======================" << endl;
        int k, n; cin >> n >> k;
        Hungarian h(n, n);
        
        vector<int> A(n);
        vector<int> B(n);
        forn(i, n) cin >> A[i] >> B[i];

        forn(i, n) forn(j, n){
            int v = 0;
            if (j < k-1){
                v = A[i] + B[i] * j;
            }else{
                v = B[i] * (k-1);
            }
            
            if(j == n-1) v += A[i];
            h.set(i, j, -v);
        }

        forn(i, n) {
            forn(j, n){
                cerr << h.cs[i][j] << ' ';
            }cerr << '\n';
        }
 
        h.assign();
        sort(all(h.ans), f);
        cerr << "aristas: " << endl;
        forn(i, n) cerr << h.ans[i].first+1 << ' ' << h.ans[i].second+1 << endl;
        cerr << endl;

        vector<int> ans;
        forn(i, h.ans.size()){
            auto p = h.ans[i];
             if (i < k-1 || i==n-1){
                ans.pb(p.first+1);
            }else{
                ans.pb(p.first+1); 
                ans.pb(-(h.ans[i].first+1));
            }
        }
        cout << ans.size() << '\n';
        for(auto a : ans) cout << a << ' ';
        cout << endl;
    }
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#else
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
    
    solve();

	return 0;
}