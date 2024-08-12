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

int sgn(T x) { return x < 0 ? -1 : !!x; }

struct line {
    T a, b, c;
    line() {}
    line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
    line(pto u, pto v) : a(v.y - u.y), b(u.x - v.x), c(a * u.x + b * u.y) {}
    int side(pto v) { return sgn(a * v.x + b * v.y - c); }
    bool inside(pto v) { return abs(a * v.x + b * v.y - c) <= EPS; }
    bool parallel(line v) { return abs(a * v.b - v.a * b) <= EPS; }
    pto inter(line v) {
        T det = a * v.b - v.a * b;
        if (abs(det) <= EPS) return pto(INF, INF);
        T x = (v.b * c - b * v.c) / det;
        T y = (a * v.c - v.a * c) / det;
        return pto(x, y);
    }
};

struct segm {
    pto s, e;
    segm(pto s_, pto e_) : s(s_), e(e_) {}
    bool inside(pto b) {
        return min(s.x, e.x) <= b.x + EPS && b.x <= max(s.x, e.x) + EPS &&
               min(s.y, e.y) <= b.y + EPS && b.y <= max(s.y, e.y) + EPS;
    }
    pto inter(segm b) {
        line l1(s, e), l2(b.s, b.e);
        if (l1.parallel(l2)) {
            if (l1.inside(b.s) && inside(b.s)) return b.s;
            if (l1.inside(b.e) && inside(b.e)) return b.e;
            if (l2.inside(s) && b.inside(s)) return s;
            if (l2.inside(e) && b.inside(e)) return e;
            return pto(INF, INF);
        }
        pto in = l1.inter(l2);
        if (inside(in) && b.inside(in)) return in;
        return pto(INF, INF);
    }
};

int main() {
    int t;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--) {
        ld x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pto p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
        segm s1(p1, p2), s2(p3, p4);
        pto inter_pt = s1.inter(s2);

        if (inter_pt == pto(INF, INF))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
