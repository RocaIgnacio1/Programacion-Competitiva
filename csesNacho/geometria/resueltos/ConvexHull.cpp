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

vector<pto> CH(vector<pto>& p) {
    if (p.size() < 3) return p;  // edge case, keep line or point
    vector<pto> ch;
    sort(p.begin(), p.end());
    forn(i, p.size()) {  // lower hull
        while (ch.size() >= 2 && ch[ch.size() - 1].left(ch[ch.size() - 2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    int k = ch.size();
    dforn(i, p.size()) {  // upper hull
        while (ch.size() >= k + 2 && ch[ch.size() - 1].left(ch[ch.size() - 2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    return ch;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    vector<pto> puntos;
    while(tt--){
        pto a;
        cin >> a.x >> a.y;
        puntos.push_back(a);
    }

    vector<pto> convex = CH(puntos);
    cout << convex.size() << endl;
    for(auto i: convex){
        cout << i.x << " " << i.y << endl;
    }

    return 0;
}