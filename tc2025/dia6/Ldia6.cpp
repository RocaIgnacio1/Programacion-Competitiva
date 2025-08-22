#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(v) (int(v.size()))

// si la entrada es entero cambiar a long long.
typedef long long T; // double could be faster but less precise
typedef long double ld;
//const T EPS = 1e-6; // if T is integer, set to 0
const T EPS = 0;
const T INF = 1e18;

struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}

	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	T operator*(pto b) { return x*b.x + y*b.y; }

	T operator^(pto b) { return x*b.y - y*b.x; }

	pto proj(pto b) { return b*((*this)*b) / (b*b); }

	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }

	

	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
	bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};

vector<pto> CH(vector<pto>& p) {
    if (p.size() < 3) return p;  // edge case, keep line or point
    vector<pto> ch;
    sort(p.begin(), p.end());
    forn(i, p.size()) {  // lower hull
        while (ch.size() >= 2 && ch[ch.size() - 1].left(ch[ch.size() - 2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    int k = ch.size();
    dforn(i, p.size()) {  // upper hull
        while (ch.size() >= k + 2 && ch[ch.size() - 1].left(ch[ch.size() - 2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    return ch;
}

ll area(vector<pto> &p){//O(p.size())
	ll area=0;
	forn(i, p.size()) area+=p[i]^p[(i+1)%p.size()];
	//if points are in clockwise order then area is negative
	return abs(area);
}

ll triArea2(pto A, pto B, pto C) {
    return ((B - A) ^ (C - A));
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<pto> a(n);
        set<pto> puntos;
        forn(i,n){
            cin >> a[i].x >> a[i].y;
            puntos.insert(a[i]);
        }

        vector<pto>convex = CH(a);
        if(convex.size()==n){
            cout << -1 << endl;
            continue;
        }
        forn(i,convex.size()){
            puntos.erase(convex[i]);
        }
        vector<pto> interiores;
        for(auto i: puntos){
            interiores.pb(i);
        }
        vector<pto> convex2 = CH(interiores);
        if(convex2.size()==0){
            cout << -1 << endl;
            continue;
        }
        int j=0;
        ll minArea = LLONG_MAX;
        ll areaTotal = area(convex);
        forn(i,convex2.size()){
            if(triArea2(convex[0],convex[1],convex2[i]) < triArea2(convex[0],convex[1],convex2[j]) ){
                j = i;
            }
        }
        
        int k = convex.size(), z = convex2.size();
     
        forn(i,convex.size()){
            ll act=triArea2(convex[i], convex[(i+1) % k], convex2[j]);
            ll sig=triArea2(convex[i], convex[(i+1) % k], convex2[(j+1) % z]);
            while(sig<act){
                j=(j+1) % z;
                act=sig;
                sig=triArea2(convex[i], convex[(i+1) % k], convex2[(j+1) % z]);
            }
            minArea=min(minArea, act);
        }

        cout << (areaTotal - minArea) << endl;
    }

    return 0;
}