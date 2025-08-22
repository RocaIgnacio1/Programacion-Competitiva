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
typedef long long T; // double could be faster but less precise
typedef long double ld;
const T EPS = 0; // if T is integer, set to 0
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

    T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
    ld dist(pto b) { return (b - (*this)).norm(); }
  
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
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


struct segment {
    pto s, e;
    segment(pto s_, pto e_) : s(s_), e(e_) {}

    //devuelve el punto del segmento más cercano a b
    pto closest(pto b) {
        pto bs = b - s, es = e - s;
        ld l = es * es;
        if (abs(l) <= EPS) return s;
        ld t = (bs * es) / l;
        if (t < 0.) return s;       // comment for lines
        else if (t > 1.) return e;  // comment for lines
        return s + (es * t);
    }
    bool inside(pto b) { //Return true if pto b is inside the segment
        return abs(s.dist(b) + e.dist(b) - s.dist(e)) < EPS; 
    }

    // si los puntos son muy grandes puede dar overflow. Usar este inside
	bool inside2(pto b) { 
		return ((s - b) ^ (e - b)) == 0 && 
				min(s.x, e.x) <= b.x && b.x <= max(s.x, e.x) &&
				min(s.y, e.y) <= b.y && b.y <= max(s.y, e.y);
	}

    pto inter(segment b) {  // if a and b are collinear, returns one point
        if ((*this).inside(b.s)) return b.s;
        if ((*this).inside(b.e)) return b.e;
        pto in = line(s, e).inter(line(b.s, b.e));
        if ((*this).inside(in) && b.inside(in)) return in;
        return pto(INF, INF);
    }


    // cuando no importa el punto
    bool intersects(segment b) {
        pto a1 = s, a2 = e, b1 = b.s, b2 = b.e;
        auto cross1 = (a2 - a1) ^ (b1 - a1);
        auto cross2 = (a2 - a1) ^ (b2 - a1);
        auto cross3 = (b2 - b1) ^ (a1 - b1);
        auto cross4 = (b2 - b1) ^ (a2 - b1);
        if ((cross1 > 0 && cross2 < 0 || cross1 < 0 && cross2 > 0) &&
            (cross3 > 0 && cross4 < 0 || cross3 < 0 && cross4 > 0))
            return true;
        return inside2(b1) || inside2(b2) || b.inside2(a1) || b.inside2(a2);
    }

};


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        pto p1,p2,p3,p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        segment s1(p1,p2), s2(p3,p4);

        if(s1.intersects(s2))cout << "YES" << endl;
        else cout << "NO" << endl;
       
    }

    return 0;
}