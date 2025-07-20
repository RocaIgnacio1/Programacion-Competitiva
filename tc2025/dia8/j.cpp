#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;
const ll MAXN = 10000000000;

const double EPS=1e-9;
struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
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

 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    int t;
    cin >> t;
    forn(k,t){
        int n, q;
        cin >> n >> q;
        vector<pto> puntos;
        forn(i,n){
            ll x,y;
            cin >> x >> y;
            puntos.push_back(pto(x,y));
        }
        map<tuple<int,int,int>,int> queries;
        forn(i,q){
            ll t1,t2,t3;
            cin >> t1 >> t2 >>t3;
            vector<pto> triangulo;
            triangulo.push_back(puntos[t1-1]);
            triangulo.push_back(puntos[t2-1]);
            triangulo.push_back(puntos[t3-1]);
            int mayor = max(t1, max(t2,t3));
            int menor = min(t1, min(t2,t3));
            int medio=0;
            if(t1!=mayor && t1!=menor)medio=t1;
            if(t2!=mayor && t2!=menor)medio=t2;
            if(t3!=mayor && t3!=menor)medio=t3;
            if(queries.find({mayor,medio,menor}) != queries.end()){
                if(queries[{mayor,medio,menor}]==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                continue;
            }
            bool ban =false;
            forn(i,n){
                if((i+1)==t1 || (i+1)==t2 || (i+1)==t3)continue;

                if(inPolygon(puntos[i], triangulo)){
                    ban=true;
                }
            }
            if(ban){
                queries[{mayor,medio,menor}]=0;
                cout<<"NO"<<endl;
            }
            else{
                queries[{mayor,medio,menor}]=1;
                cout<<"YES"<<endl;
            }
        }
    }
   
    return 0;
}
