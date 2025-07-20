#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define ll long long
#define  sz(d) d.size()

using namespace std;

#define ld double

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
typedef pto vec;



// returns convex hull of p in CCW order
// left must return >=0 to delete collinear points
void CH(vector<pto>& P, vector<pto> &S){
	S.clear();
	sort(P.begin(), P.end());//first x, then y
	forn(i, sz(P)){//lower hull
		while(sz(S)>= 2 && S[sz(S)-1].left(S[sz(S)-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
	int k=sz(S);
	dforn(i, sz(P)){//upper hull
		while(sz(S) >= k+2 && S[sz(S)-1].left(S[sz(S)-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();

}

void normalize(vector<pto> &pt){//delete collinear points first!
	//this makes it clockwise:
    if(pt[2].left(pt[0], pt[1])) reverse(pt.begin(), pt.end());
	int n=sz(pt), pi=0;
	forn(i, n)
		if(pt[i].x<pt[pi].x || (pt[i].x==pt[pi].x && pt[i].y<pt[pi].y))
			pi=i;
	vector<pto> shift(n);//puts pi as first point
    forn(i, n) shift[i]=pt[(pi+i)%n];
    pt.swap(shift);
}

bool inPolygon(pto p, vector<pto> pt){
    normalize(pt);
	//call normalize first!
	if(p.left(pt[0], pt[1]) || p.left(pt[sz(pt)-1], pt[0])) return false;
	int a=1, b=sz(pt)-1;
	while(b-a>1){
		int c=(a+b)/2;
		if(!p.left(pt[0], pt[c])) a=c;
		else b=c;
	}
	return !p.left(pt[a], pt[a+1]);
}


int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int t;
    cin>>t;
    forn(j,t){
        int n;
        cin >> n;
        vector<pto> p;
        forn(i,n){
            ll a, b;
            cin >> a >> b;
            p.push_back(pto(a,b));
        }

        vector<pto> convex;
        CH(p,convex);
        
        forn(i,convex.size()){
            cout << convex[i].x << " " << convex[i].y << endl;
        } 

        /*
        if(n-convex.size()<=2){
            //caso sin convex interna
        }*/
        vector<pto> internos;
        forn(i,n){
            if(!inPolygon(p[i],convex)){
                internos.push_back(p[i]);
            }
        }
        forn(i,sz(internos)){
            cout << internos[i].x << " " << internos[i].y << endl;
        }


        vector<pto> interna;
        CH(p,convex);
            
        cout << endl;
    }
    
    return 0;
}