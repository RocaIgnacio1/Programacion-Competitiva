#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-6; 
const ll INF = 1e18+100;

struct pto {
    ld x, y;
    pto(ld x=0, ld y=0) : x(x), y(y) {}
    pto operator+(pto b) { return pto(x+b.x, y+b.y); }
    pto operator-(pto b) { return pto(x-b.x, y-b.y); }
    pto operator+(ld k) { return pto(x+k, y+k); }
    pto operator*(ld k) { return pto(x*k, y*k); }
    pto operator/(ld k) { return pto(x/k, y/k); }
    double operator^(pto b) { return x*b.y - y*b.x; }
    bool operator==(pto b) { return abs(x - b.x) <= EPS && abs(y - b.y) <= EPS; }
};

ld area(vector<pto> &p){//O(sz(p))
	ld area=0;
	forn(i, p.size()) area+=p[i]^p[(i+1)%p.size()];
	//if points are in clockwise order then area is negative
	return abs(area)/2;
}

#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    pto c,s;
    int z1, z2;
    cin >> n;
    cin >> c.x >> c.y >> z1;
    cin >> s.x >> s.y >> z2;

    ld t = ld(-z2) / (z1 - z2);
    ld x = s.x + t * (c.x - s.x); 
    ld y = s.y + t * (c.y - s.y); 
    pto sol(x, y);

    
    vector<pto> poligono(n);
    forn(i,n){
        cin >> poligono[i].x >> poligono[i].y;
    }

    ld a = area(poligono);
    ld suma=0;
    forn(i,n){
        suma += abs((poligono[i] - sol) ^ (poligono[(i + 1) % n] - sol)) / 2;
    }  
    if(suma-a<EPS)cout << "N" << endl;
    else cout << "S" << endl;
    
    return 0;
}