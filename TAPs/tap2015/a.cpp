#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define mos(v) for(auto i : v) cout << i << " ";
typedef double T;
typedef long double ld;
const long long INF = 1e18;
const ld EPS=1e-6;
struct pto{
	ld x, y;
	pto(ld x=0, ld y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(ld a){return pto(x+a, y+a);}
	pto operator*(ld a){return pto(x*a, y*a);}
	pto operator/(ld a){return pto(x/a, y/a);}
	ld operator*(pto a){return x*a.x+y*a.y;}
	ld operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	ld norm(){return sqrt(x*x+y*y);}
	ld norm_sq(){return x*x+y*y;}
};
ld dist(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

struct line{
	line() {}
	ld a,b,c;//Ax+By=C
	//pto MUST store float coordinates!
	line(ld a, ld b, ld c):a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
};

struct Circle{
	pto o;
	int r;
    Circle(pto centro, int radio) : o(centro), r(radio) {}
};

#define sqr(a) ((a)*(a))
#define feq(a,b) (fabs((a)-(b))<EPS)
pair<T, T> ecCuad(T a, T b, T c){//a*x*x+b*x+c=0
	T dx = sqrt(b*b-4.0*a*c);
	return make_pair((-b + dx)/(2.0*a),(-b - dx)/(2.0*a));
}
pair<pto, pto> interCL(Circle c, line l){
	bool sw=false;
	if((sw=feq(0,l.b))){
	swap(l.a, l.b);
	swap(c.o.x, c.o.y);
	}
	pair<T, T> rc = ecCuad(
	sqr(l.a)+sqr(l.b),
	2.0*l.a*l.b*c.o.y-2.0*(sqr(l.b)*c.o.x+l.c*l.a),
	sqr(l.b)*(sqr(c.o.x)+sqr(c.o.y)-sqr(c.r))+sqr(l.c)-2.0*l.c*l.b*c.o.y
	);
	pair<pto, pto> p( pto(rc.first, (l.c - l.a * rc.first) / l.b),
					  pto(rc.second, (l.c - l.a * rc.second) / l.b) );
	if(sw){
	swap(p.first.x, p.first.y);
	swap(p.second.x, p.second.y);
	}
	return p;
}
pair<pto, pto> interCC(Circle c1, Circle c2){
	line l;
	l.a = c1.o.x-c2.o.x;
	l.b = c1.o.y-c2.o.y;
	l.c = (sqr(c2.r)-sqr(c1.r)+sqr(c1.o.x)-sqr(c2.o.x)+sqr(c1.o.y)
	-sqr(c2.o.y))/2.0;
	return interCL(c1, l);
}

int main() {
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    while(cin >> n){
		vector<Circle> circulos;
		forn(i,n){
			int x,y,r;
			cin >> x >> y >> r;
			Circle a(pto(x,y),r);
			circulos.push_back(a);
		}
		set<pto> posibles;
		forn(i,n){
			for(int j=i+1;j<n;j++){
				pair<pto,pto> puntos = interCC(circulos[i],circulos[j]);
				if (!isnan(puntos.first.x) && !isnan(puntos.first.y)) {
					posibles.insert(puntos.first);
				}
				if (!isnan(puntos.second.x) && !isnan(puntos.second.y)) {
					posibles.insert(puntos.second);
				}
			}
		}
		// los centros tambien son puntos posibles. (si esta un circulo contenido en otro)
		forn(i,n){
			posibles.insert(circulos[i].o);
		}	
		int maximo=0, ans=0;
		for(const auto& p : posibles){
			maximo=0;
			forn(j,circulos.size()){
				ld distancia = dist(circulos[j].o,p);
				if((circulos[j].r*circulos[j].r)>=distancia) maximo++;
			}
			ans = max(ans,maximo);
		}
		cout << ans << endl;
	}
    return 0;
}
