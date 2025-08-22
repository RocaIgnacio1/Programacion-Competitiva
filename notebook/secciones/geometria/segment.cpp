#include "pto.cpp"
#include "line.cpp"

struct segment {
    pto s, e;
    segment(pto s_, pto e_) : s(s_), e(e_) {}

    //devuelve el punto del segmento más cercano a b
    pto closest(pto b) {
        pto bs = b - s, es = e - s;
        ld l = es * es;
        if (abs(l) <= EPS) return s;
        ld t = (bs * es) / l;
        if (t < 0.) return s;       // comment for lines
        else if (t > 1.) return e;  // comment for lines
        return s + (es * t);
    }
    bool inside(pto b) { //Return true if pto b is inside the segment
        return abs(s.dist(b) + e.dist(b) - s.dist(e)) < EPS; 
    }

    // si los puntos son muy grandes puede dar overflow. Usar este inside
	bool inside2(pto b) { 
		return ((s - b) ^ (e - b)) == 0 && 
				min(s.x, e.x) <= b.x && b.x <= max(s.x, e.x) &&
				min(s.y, e.y) <= b.y && b.y <= max(s.y, e.y);
	}

    pto inter(segment b) {  // if a and b are collinear, returns one point
        if ((*this).inside(b.s)) return b.s;
        if ((*this).inside(b.e)) return b.e;
        pto in = line(s, e).inter(line(b.s, b.e));
        if ((*this).inside(in) && b.inside(in)) return in;
        return pto(INF, INF);
    }


    // cuando no importa el punto
    bool intersects(segment b) {
        pto a1 = s, a2 = e, b1 = b.s, b2 = b.e;
        auto cross1 = (a2 - a1) ^ (b1 - a1);
        auto cross2 = (a2 - a1) ^ (b2 - a1);
        auto cross3 = (b2 - b1) ^ (a1 - b1);
        auto cross4 = (b2 - b1) ^ (a2 - b1);
        if ((cross1 > 0 && cross2 < 0 || cross1 < 0 && cross2 > 0) &&
            (cross3 > 0 && cross4 < 0 || cross3 < 0 && cross4 > 0))
            return true;
        return inside(b1) || inside(b2) || b.inside(a1) || b.inside(a2);
    }

};
