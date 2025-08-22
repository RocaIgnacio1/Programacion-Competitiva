#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

// si la entrada es entero cambiar a long long.
typedef long double T; // double could be faster but less precise
typedef long double ld;
const T EPS = 1e-6; // if T is integer, set to 0
const T INF = 1e18;

struct pto{
	T x, y;
    //constructor. pto a = (0,0)
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}

    //operadores basicos
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }

	T operator*(pto b) { return x*b.x + y*b.y; }
	T operator^(pto b) { return x*b.y - y*b.x; }
    bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
  
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
};

ld area(vector<pto> &p){//O(sz(p))
	ld area=0;
	forn(i, p.size()) area+=p[i]^p[(i+1)%p.size()];
	//if points are in clockwise order then area is negative
	return abs(area)/2;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    tt=1;
    while(tt--){
        int n;
        cin >> n;
        int sx,sy,sz,cx,cy,cz;
        cin >> sx >> sy >> sz >> cx >> cy >> cz;

        /*
            z = z0 + lambda * (sz-cz)
            0 = z0 + lambda * (sz-cz)
            -z0 = lambda * (sz-cz)
            -z0/(sz-cz) = lambda
        */
        ld lambda = ld(-sz) / (sz-cz);
        /*
            x = x0 + lambda * (sz-cz)
            y = y0 + lambda * (sz-cz)
        */
        pto punto;
        punto.x = sx + lambda*(sx-cx);
        punto.y = sy + lambda*(sy-cy);

        vector<pto> a(n);
        forn(i,n)cin >> a[i].x >> a[i].y;
        ld areaTotal = area(a);
        ld areaSombra = 0;
        forn(i,n){
            vector<pto> calc;
            if(i==n-1){
                calc = {a[i],a[0],punto};
            }else{
                calc = {a[i],a[i+1],punto};
            }
            areaSombra+= area(calc);
        }

        if(areaSombra-areaTotal<EPS){
            cout << "N" << endl;
        }else{
            cout << "S" << endl;
        }
        
    }   

    return 0;
}