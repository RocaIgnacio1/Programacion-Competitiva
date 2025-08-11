#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

#define ld double
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
void CH(vector<pto>& P, vector<pto> &S){
	S.clear();
	sort(P.begin(), P.end());//first x, then y
	forn(i, P.size()){//lower hull
		while(S.size()>= 2 && S[S.size()-1].left(S[S.size()-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
	int k=S.size();
	dforn(i, P.size()){//upper hull
		while(S.size() >= k+2 && S[S.size()-1].left(S[S.size()-2], P[i])) S.pop_back();
		S.pb(P[i]);
	}
	S.pop_back();
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    
    vector<pto> b;
    map<pto,int> indices;
    forn(i,n){
        int x,y;
        cin >> x >> y;
        b.push_back(pto(x,y));
        indices[pto(x,y)] = i+1;
    }

    vector<pto> a;
    CH(b,a);
    vector<int> ans;
    for(auto i:a){
        ans.push_back(indices[i]);
    }
    sort(ans.begin(),ans.end());
    forn(i,ans.size()){
        if(i!=0 && ans[i]==ans[i-1])continue;
        cout << ans[i] << " ";
    }
    cout << endl;
  
    return 0;
}