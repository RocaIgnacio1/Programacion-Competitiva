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

typedef long long T; // double could be faster but less precise
typedef long double ld;
//const T EPS = 1e-9; // if T is integer, set to 0
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

	// dot product
    /*  a · b = |a| * |b| * cos(θ)
        proy_a_b = ( (a·b) / |b|² ) * b
        a ⟂ b  ⇔  a·b = 0  (o |a·b| < EPS en flotantes)
    */
	T operator*(pto b) { return x*b.x + y*b.y; }

	// cross product
	T operator^(pto b) { return x*b.y - y*b.x; }
    /*
        |a × b| = |a| * |b| * sin(θ)
        > 0  →  b está a la izquierda de a  (rotación CCW menor a 180°)
        < 0  →  b está a la derecha de a    (rotación CW menor a 180°)
        = 0  →  a y b son colineales.
        Es el área con signo del paralelogramo formado por a y b.
        El área del triángulo definido por a y b es |a × b| / 2.
    */
	// vector projection of this above b
	pto proj(pto b) { return b*((*this)*b) / (b*b); }

	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
    ll dist2(pto b) { return (b - (*this)).norm_sq(); }

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

struct CmpY {
    bool operator()(const pto& a, const pto& b) const {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    }
};

ll closest_pair(vector<pto>& pts) {
    sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
        return a.x < b.x;
    });

    set<pto, CmpY> active;
    ll d = LLONG_MAX;
    int j = 0;

    for (int i = 0; i < (int)pts.size(); i++) {
        pto p = pts[i];

        while (j < i && (p.x - pts[j].x)*(p.x - pts[j].x) > d) {
            active.erase(pts[j]);
            j++;
        }

        // vecinos en [p.y - sqrt(d), p.y + sqrt(d)]
        ll lim = (ll) sqrtl((long double)d) + 1;
        pto low = {p.x, p.y - lim};
        pto high = {p.x, p.y + lim};

        auto itlow = active.lower_bound(low);
        auto ithigh = active.upper_bound(high);

        for (auto it = itlow; it != ithigh; ++it) {
            d = min(d, p.dist2(*it));
        }

        active.insert(p);
    }
    return d;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pto> a(n);
    forn(i,n){
        cin >> a[i].x >> a[i].y;
    }
    cout << closest_pair(a) << endl;

    return 0;
}