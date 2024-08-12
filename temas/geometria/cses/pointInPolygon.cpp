#include <bits/stdc++.h>
#include <algorithm> 
#include <numeric>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
typedef long long ll;
#define INF LLONG_MAX
const double EPS = 1e-9;

struct pto {
    double x, y;
    pto() : x(0), y(0) {} 
    pto(ll _x, ll _y) : x(_x), y(_y) {}
    pto operator+(pto b) { return pto(x+b.x, y+b.y); }
    pto operator-(pto b) { return pto(x-b.x, y-b.y); }
    pto operator+(double k) { return pto(x+k, y+k); }
    pto operator*(double k) { return pto(x*k, y*k); }
    pto operator/(double k) { return pto(x/k, y/k); }
    double operator*(pto b) { return x*b.x + y*b.y; }
    pto proj(pto b) { return b*((*this)*b) / (b*b); }
    double operator^(pto b) { return x*b.y - y*b.x; } 
    bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
    double norm(){return sqrt(x*x+y*y);}
    double norm_sq(){return x*x+y*y;}

};
double dist(pto a, pto b){return (b-a).norm();}
bool inPolygon(pto v, vector<pto>& P) {
	bool c = false;
	forn(i, P.size()){
		int j=(i+1)%P.size();
		if((P[j].y>v.y) != (P[i].y > v.y) &&
	(v.x < (P[i].x - P[j].x) * (v.y-P[j].y) / (P[i].y - P[j].y) + P[j].x))
			c = !c;
	}
	return c;
}


int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line() {}
	double a,b,c;//Ax+By=C
//pto MUST store float coordinates!
	line(double a, double b, double c):a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
};

struct segm{
	pto s,f;
	segm(pto s, pto f):s(s), f(f) {}
	pto closest(pto p) {//use for dist to point
	   double l2 = dist(s, f);
	   if(l2==0.) return s;
	   double t =((p-s)*(f-s))/l2;
	   if (t<0.) return s;//not write if is a line
	   else if(t>1.)return f;//not write if is a line
	   return s+((f-s)*t);
	}
   bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS;}
};

//NOTA: Si los segmentos son coolineales solo devuelve un punto de interseccion
pto inter(segm s1, segm s2){
    if(s1.inside(s2.s)) return s2.s; //Fix cuando son colineales
    if(s1.inside(s2.f)) return s2.f; //Fix cuando son colineales
	pto r=inter(line(s1.s, s1.f), line(s2.s, s2.f));
    if(s1.inside(r) && s2.inside(r)) return r;
	return pto(INF, INF);
}



int main(){
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<pto> poligono;
    forn(j,n){
        ll x1,y1;
        cin >> x1 >> y1;
        pto p1(x1,y1);
        poligono.push_back(p1);
    }
    
    forn(j,m){
        ll x1,y1;
        cin >> x1 >> y1;
        pto p1(x1,y1);
        if(inPolygon(p1,poligono)){
            //adentro/limite
            pto v1 = poligono[0];
            bool ban=false;
            for(int i=1;i<n;i++){
                pto v2=poligono[i];
                segm lado(v1,v2);
                
                if(lado.inside(p1)){
                    ban = true;
                    
                    break;
                }
                v1 = v2;
            }
            v1=poligono[0];
            pto v2=poligono[n-1];
            segm lado(v1,v2);
            if(lado.inside(p1)){
                ban = true;
                
            }
            if((p1.x==v1.x && p1.y==v1.y) || (p1.x==v2.x && p1.y==v2.y)){
                ban=true;
                
                //cout << p1.x << " " << p1.y << " "<< v1.x << " " <<v1.y <<endl;
            }
            if(ban){
                cout << "BOUNDARY" << endl;
                //cout << "hola" <<endl;
            }else{
                cout << "INSIDE" << endl;
            }
        }else{
            //limite/afuera
            pto v1 = poligono[0];
            bool ban=false;
            for(int i=1;i<n;i++){
                pto v2=poligono[i];
                segm lado(v1,v2);
                if((p1.x==v1.x && p1.y==v1.y) || (p1.x==v2.x && p1.y==v2.y)){
                    ban=true;
                }
                if(lado.inside(p1)){
                    ban = true;
                    break;
                }
                v1 = v2;
            }
            v1=poligono[0];
            pto v2=poligono[n-1];
            segm lado(v1,v2);
            if(lado.inside(p1)){
                ban = true;
            }
            if((p1.x==v1.x && p1.y==v1.y) || (p1.x==v2.x && p1.y==v2.y)){
                ban=true;
                //cout << p1.x << " " << p1.y << " "<< v1.x << " " <<v1.y <<endl;
            }
            if(ban){
                cout << "BOUNDARY" << endl;
            }else{
                cout << "OUTSIDE" << endl;
            }
            
        }
    }
    
    
}