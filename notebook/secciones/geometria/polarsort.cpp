/*
funcionamiento:
    vector<pto> puntos = {pto(1, 2), pto(2, 1), pto(-1, -1), pto(0, 2)};
    pto referencia(1, 1); // punto de referencia
    sort(puntos.begin(), puntos.end(), Cmp(referencia));
*/

struct Cmp{//orden total de puntos alrededor de un punto r
	pto r;
	Cmp(pto r):r(r) {}
	int cuad(const pto &a) const{
		if(a.x > 0 && a.y >= 0)return 0;
		if(a.x <= 0 && a.y > 0)return 1;
		if(a.x < 0 && a.y <= 0)return 2;
		if(a.x >= 0 && a.y < 0)return 3;
		assert(a.x ==0 && a.y==0);
		return -1;
	}
	bool cmp(const pto&p1, const pto&p2)const{
		int c1 = cuad(p1), c2 = cuad(p2);
		if(c1==c2) return p1.y*p2.x<p1.x*p2.y;
        else return c1 < c2;
	}
    bool operator()(const pto&p1, const pto&p2) const{
    return cmp(pto(p1.x-r.x,p1.y-r.y),pto(p2.x-r.x,p2.y-r.y));
    }
};

