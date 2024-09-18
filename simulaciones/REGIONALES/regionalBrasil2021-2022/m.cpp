#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;
#ifdef EBUG
//local
#else
//judge
#endif

struct triple{
    ll first, second, third;
};

bool sortBy(const triple &a, const triple &b){
    if(a.second==b.second) return a.third<b.third;
    return a.second<b.second;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<triple> x;
    forn(i,n){
        ll t,d;
        cin >> t >> d;
        triple a;
        a.first = t;
        a.second = d;
        a.third = i+1;
        x.pb(a);
    }
    sort(x.begin(), x.end(),sortBy);
    
    ll suma=0;
    forn(i,n){
        suma+=x[i].first;
        if(suma>x[i].second){
            cout << "*" << endl;
            return 0;
        }
    }
    forn(i,n){
        cout << x[i].third << " ";
    }
    cout << endl;

    return 0;
}