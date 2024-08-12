#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double

struct pto {
    ll x, y;
    pto() : x(0), y(0) {} 
    pto(ll _x, ll _y) : x(_x), y(_y) {}
    pto operator+(pto b) { return pto(x+b.x, y+b.y); }
    pto operator-(pto b) { return pto(x-b.x, y-b.y); }
    pto operator+(ll k) { return pto(x+k, y+k); }
    pto operator*(ll k) { return pto(x*k, y*k); }
    pto operator/(ll k) { return pto(x/k, y/k); }
    ll operator*(pto b) { return x*b.x + y*b.y; }
    pto proj(pto b) { return b*((*this)*b) / (b*b); }
    ll operator^(pto b) { return x*b.y - y*b.x; } 
    ld norm() { return sqrt(x*x + y*y); }
    ld dist(pto b) { return (b - (*this)).norm(); }
};

int main(){
    //freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    forn(i,t){
        ll x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        pto p1(x1,y1);
        pto p2(x2,y2);
        pto p3(x3,y3);
        
        pto vec1 = p2-p1;
        pto vec2 = p3-p1;
        
        if((vec1^vec2) > 0){
            cout << "LEFT" << endl;
        }else{
            if((vec1^vec2)<0){
                cout << "RIGHT" << endl;
            }else{
                cout << "TOUCH" << endl;
            }
        }
        
    }
}