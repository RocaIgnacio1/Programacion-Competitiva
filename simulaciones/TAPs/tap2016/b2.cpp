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
    
    ld ans = (ld)0;
    if(A.empty()&&B.empty()) ans=a[inicio][fin];
    else{
        if(A.empty()){
            ans = a[inicio][B[0]];  
            forr(i,1,B.size())ans+=a[B[i-1]][B[i]];
            ans += a[B[B.size()-1]][fin];
        }
        if(B.empty()){
            ans = a[inicio][A[0]]; 
            forr(i,1,A.size())ans+=a[A[i-1]][A[i]];
            ans += a[A[A.size()-1]][fin];
        }
        if(!B.empty() && !A.empty()){
            ld forma1 = (ld)0;
            forma1 = a[inicio][B[0]];  
            forr(i,1,B.size())forma1+=a[B[i-1]][B[i]];
            forma1 += a[B[B.size()-1]][A[0]];
            forr(i,1,A.size())forma1+=a[A[i-1]][A[i]];
            forma1 += a[A[A.size()-1]][fin];
            
            ld forma2=(ld)0;
            forma2 = a[inicio][A[0]];
            forr(i,1,A.size())forma2+=a[A[i-1]][A[i]];
            forma2 += a[A[A.size()-1]][B[0]];
            forr(i,1,B.size())forma2+=a[B[i-1]][B[i]];
            forma2 += a[B[B.size()-1]][fin];

            ans = min(forma1,forma2);
        }
    }
    

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}