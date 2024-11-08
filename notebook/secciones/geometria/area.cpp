double area(vector<pto> &p){//O(sz(p))
	double area=0;
	forn(i, sz(p)) area+=p[i]^p[(i+1)%sz(p)];
	//if points are in clockwise order then area is negative
	return abs(area)/2;
}