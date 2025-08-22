#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define forr(i, a, b) for (int i = (a); i < (b); i++)
 
#define sz(v) (int(v.size()))
#define pb push_back
 
// si la entrada es entero cambiar a long long.
typedef long double T; // double could be faster but less precise
typedef long double ld;
const ld EPS = 1e-9; // if T is integer, set to 0
//const T EPS = 0;
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
   
	// vector projection of this above b
	pto proj(pto b) { return b*((*this)*b) / (b*b); }
 
	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
 
	//rotate by theta rads CCW w.r.t. origin (0,0)
	pto rotate(T ang) {
		return pto(x*cosl(ang) - y*sinl(ang), x*sinl(ang) + y*cosl(ang));
	}
 
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
	bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};
 
int sgn(T x) { return x < 0 ? -1 : !!x; }
struct line {
	T a, b, c;  // Ax+By=C
	line() {}
	line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
	// TO DO: check negative C (multiply everything by -1)
	line(pto u, pto v) : a(v.y - u.y), b(u.x - v.x), c(a * u.x + b * u.y) {}
	int side(pto v) { return sgn(a * v.x + b * v.y - c); }
	bool inside(pto v) { return abs(a * v.x + b * v.y - c) <= EPS; }
	bool parallel(line v) { return abs(a * v.b - v.a * b) <= EPS; }
	pto inter(line v) {
		T det = a * v.b - v.a * b;
		if (abs(det) <= EPS) return pto(INF, INF);
		return pto(v.b * c - b * v.c, a * v.c - v.a * c) / det;
	}
};
 
struct segm {
	pto s, e;
	segm(pto s_, pto e_) : s(s_), e(e_) {}
	pto closest(pto b) {
		pto bs = b - s, es = e - s;
		ld l = es * es;
		if (abs(l) <= EPS) return s;
		ld t = (bs * es) / l;
		if (t < 0.) return s;       // comment for lines
		else if (t > 1.) return e;  // comment for lines
		return s + (es * t);
	}
	bool inside(pto b) { return abs(s.dist(b) + e.dist(b) - s.dist(e)) < EPS; }
 
	// si los puntos son muy grandes puede dar overflow. Usar este inside
	bool inside2(pto b) { 
    // usamos long double para evitar overflow
		long double cross = (long double)(s.x - b.x) * (e.y - b.y) - (long double)(s.y - b.y) * (e.x - b.x);
		if (fabsl(cross) > 1e-9) return false;
		return min(s.x, e.x) <= b.x && b.x <= max(s.x, e.x) &&
			min(s.y, e.y) <= b.y && b.y <= max(s.y, e.y);
	}

 
	pto inter(segm b) {  // if a and b are collinear, returns one point
		if ((*this).inside(b.s)) return b.s;
		if ((*this).inside(b.e)) return b.e;
		pto in = line(s, e).inter(line(b.s, b.e));
		if ((*this).inside(in) && b.inside(in)) return in;
		return pto(INF, INF);
	}
};
 
struct poly{
	vector<pto> pt;
	poly(){}
	poly(vector<pto> pt_) : pt(pt_) {}
	
 
	// for convex or concave polygons
	// excludes boundaries, check it manually
	bool inside(pto p) { 
		bool c = false;
		for (int i = 0; i < (int)pt.size(); i++) {
			int j = (i+1) % pt.size();
			// si el punto está en la horizontal entre los vértices
			if ((pt[i].y > p.y) != (pt[j].y > p.y)) {
				long double x_intersect = (long double)(pt[j].x - pt[i].x) * (p.y - pt[i].y) / (long double)(pt[j].y - pt[i].y) + pt[i].x;
				if (p.x < x_intersect)
					c = !c;
			}
		}
		return c;
	}
};
 
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
	cin >> n >> m;
	vector<pto> pol(n);
	forn(i,n){
		cin >> pol[i].x >> pol[i].y;
	}
	vector<pto> puntos(m);
	forn(i,m){
		cin >> puntos[i].x >> puntos[i].y;
	}
 
	poly poligono(pol);
 
	forn(j,m){
		bool ans=false;
		forn(i,n){
			segm arista(poligono.pt[i],poligono.pt[(i+1)%n]);
			if (arista.inside2(puntos[j])) {
				ans = true;
				break;
			}
		}
		if(ans){
			cout << "BOUNDARY" << endl;
		}else{
			if(poligono.inside(puntos[j])){
				cout << "INSIDE" << endl;
			}else{
				cout << "OUTSIDE" << endl;
			}
		}
	}
	
    return 0;
}