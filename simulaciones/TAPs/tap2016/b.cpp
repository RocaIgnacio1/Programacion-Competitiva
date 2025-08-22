#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

typedef long long T; 
typedef double ld;
const T EPS = 0;
const T INF = 1e18;

struct pto{
	T x, y;
    //constructor. pto a = (0,0)
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
 
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	T operator*(pto b) { return x*b.x + y*b.y; }
	T operator^(pto b) { return x*b.y - y*b.x; }
	T norm_sq() { return x*x + y*y; }
    ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }

};

int n, inicio, fin;
vector<int> A, B;
ld a[4010][4010];
vector<vector<array<ld,2>>> dp;

ld solve(int i, int j, int ubi){
    if(dp[i][j][ubi] != -1) return dp[i][j][ubi];

    if(i==A.size() && j==B.size()){
        if(ubi==0 && i>0) return dp[i][j][ubi] = a[A[i-1]][fin];
        if(ubi==1 && j>0) return dp[i][j][ubi] = a[B[j-1]][fin];
    }

    ld ans = (ld)1000000000000, dist;

     if(ubi==0){
        // seguir por A
        if(i<A.size()){
            dist = a[A[i-1]][A[i]];
            ans = min(ans, solve(i+1,j,0)+dist);
        }
        // cambiar a B
        if(j<B.size()){
            dist = a[A[i-1]][B[j]];
            ans = min(ans, solve(i,j+1,1)+dist);
        }
    }

    if(ubi==1){
        // seguir por B
        if(j<B.size()){
            dist = a[B[j-1]][B[j]];
            ans = min(ans, solve(i,j+1,1)+dist);
        }
        // cambiar a A
        if(i<A.size()){
            dist = a[B[j-1]][A[i]];
            ans = min(ans, solve(i+1,j,0)+dist);
        }
    }

    return dp[i][j][ubi] = ans;
}



int main() {
    HOLA;
    #ifdef EBUG
    freopen("b.txt", "r", stdin);
    #endif

    cin >> n >> inicio >> fin;
        
    vector<pto> puntos(n);
    forn(i,n){
        cin >> puntos[i].x >> puntos[i].y;
    }
    
    forn(i,n){
        forn(j,n){
        a[i][j] = puntos[i].dist(puntos[j]);
        a[j][i] = puntos[i].dist(puntos[j]);
        }
    }

    inicio--;
    fin--;
    if(inicio<fin){
        // inicio < fin
        for(int i=inicio+1; i<fin; i++){
            A.push_back(i);
        }

        for(int i=inicio-1; i>=0; i--){
            B.push_back(i);
        }

        for(int i=n-1; i>fin; i--){
            B.push_back(i);
        }
    }else{
        // inicio > fin
        for(int i=inicio+1; i<n; i++){
            A.push_back(i);
        }
        for(int i=0; i<fin; i++){
            A.push_back(i);
        }
        for(int i=fin+1; i<inicio; i++){
            B.push_back(i);
        }
        reverse(B.begin(),B.end());
    }
    dp.assign(A.size()+1, vector<array<ld,2>>(B.size()+1, {-1,-1}));

    ld ans = (ld)1000000000000;
    if(!A.empty())ans=min(ans, solve(1,0,0)+ a[inicio][A[0]]);
    if(!B.empty())ans=min(ans, solve(0,1,1)+ a[inicio][B[0]]);
    if(A.empty() && B.empty()) ans = a[inicio][fin];
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}