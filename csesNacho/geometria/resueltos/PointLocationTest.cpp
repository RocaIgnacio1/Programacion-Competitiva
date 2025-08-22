#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

// si la entrada es entero cambiar a long long.
typedef long long T; // double could be faster but less precise
typedef long double ld;
const T EPS = 0; // if T is integer, set to 0
const T INF = 1e18;

struct pto{
	T x, y;
    //constructor. pto a = (0,0)
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}

    //operadores basicos
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }

	T operator*(pto b) { return x*b.x + y*b.y; }
	T operator^(pto b) { return x*b.y - y*b.x; }
  
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
};

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
        pto p1,p2,p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        ll result = (p2-p1)^(p3-p1);
        if(result>0){
            cout << "LEFT" << endl;
        }else{
            if(result<0){
                cout << "RIGHT" << endl;
            }else{
                cout << "TOUCH" << endl;
            }
        }
    }

    return 0;
}