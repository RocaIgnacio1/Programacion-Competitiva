#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
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

int main(){
    //freopen("input.txt","r",stdin);
    int n;
    while(cin >> n){
        vector<int> x;
        vector<int> y;
        vector<int> r;
        forn(i,n){
            int a,b,c;
            cin >> a >> b >> c;
            x.push_back(a);
            y.push_back(b);
            r.push_back(c);
        }
        bool ban=true;
        forn(i,n){
            forn(j,n){
                if(x[i]==x[j] && y[i]==y[j] && r[i]==r[j])continue;

                pto p1(x[i],y[i]);
                pto p2(x[j],y[j]);
                //cout << x[i] << " " << y[i] << " " << r[i] << endl; 
                //cout << x[j] << " " << y[j] << " " << r[j] << endl;
                //cout << r[i] << endl;
                //cout <<  dist(p1,p2)+r[j] << endl;
                if(r[i]>(dist(p1,p2)+r[j]) || r[j]>(dist(p1,p2)+r[i]))continue;
                if((r[i]+r[j]) >= dist(p1,p2) ){
                    //cout << "hola"<< endl;
                    ban=false;
                }
            }
        }
        if(ban){
            cout << "SI" << endl;
        }else{
            cout << "NO" << endl;
        }
        /*
        forn(i,n){
            cout << x[i] << " " << y[i] << " " << r[i] << endl;
        }
        */
    }
}