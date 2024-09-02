#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define mos(v) for(auto i : v) cout << i << " ";
typedef long long T;
typedef long double ld;
const T EPS = 1e-9;
const T INF = 1e18;

struct pto {
    T x, y;
    pto() : x(0), y(0) {}
    pto(T _x, T _y) : x(_x), y(_y) {}
    pto operator+(pto b) { return pto(x + b.x, y + b.y); }
    pto operator-(pto b) { return pto(x - b.x, y - b.y); }
    pto operator*(T k) { return pto(x * k, y * k); }
    pto operator/(T k) { return pto(x / k, y / k); }
    T operator*(pto b) { return x * b.x + y * b.y; }
    T operator^(pto b) { return x * b.y - y * b.x; }
    ld dist(pto b) { return sqrtl((b - (*this)) * (b - (*this))); }
    bool operator<(const pto &b) const {
        return x < b.x - EPS || (abs(x - b.x) <= EPS && y < b.y - EPS);
    }
    bool operator==(pto b) { return abs(x - b.x) <= EPS && abs(y - b.y) <= EPS; }
};


int main() {
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
        //cout << "hola";
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<pto> centros;
        forn(i,n){
            ll x1, y1;
            cin >> x1 >> y1;
            pto a(x1,y1);
            centros.push_back(a);
        }
        ll xa,ya,xb,yb;
        cin >> xa >> ya >> xb >> yb;
        pto A(xa, ya), B(xb, yb);
        ld minimo=INF;
        forn(i,n){
            //cout <<  centros[i].x << " " << centros[i].y << endl;
            minimo = min(minimo, centros[i].dist(B));
        }
        ld distancia = A.dist(B);
        
        //cout <<  fixed << setprecision(9) << distancia << " " << minimo << endl;
        
        if(distancia<minimo){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}
