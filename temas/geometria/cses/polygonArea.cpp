#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
 
const double EPS=1e-9;
struct pto{
	ll x, y;
	pto(ll x=0, ll y=0):x(x),y(y){}
	ll operator^(pto a){return x*a.y-y*a.x;}
};

ll area(vector<pto> &p){//O(sz(p))
	ll area=0;
	forn(i, p.size()) area+=p[i]^p[(i+1)%p.size()];
	//if points are in clockwise order then area is negative
	return abs(area);
}
 
int main(){
    //freopen("input.txt", "r", stdin);
 
    int n;
    cin >> n;
    vector<pto> vertices;
    forn(j,n){
        ll x1,y1;
        cin >> x1 >> y1;
        pto p1(x1,y1);
        vertices.push_back(p1);
    }
    cout << area(vertices) << endl;
}
