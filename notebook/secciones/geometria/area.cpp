#include "pto.cpp"
#define forn(i, n) for(int i = 0; i < n; i++)
double area(vector<pto> &p){//O(p.size())
	double area=0;
	forn(i, p.size()) area+=p[i]^p[(i+1)%p.size()];
	//if points are in clockwise order then area is negative
	return abs(area)/2;
	// si los puntos son enteros abs(area) es siempre entero
}
