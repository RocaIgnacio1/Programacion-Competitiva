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


int lis(vector<ll> const& a) {
    int n = a.size();
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        ll l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] <= a[i] && a[i] <= d[l] && a[i] >= 0)
            d[l] = a[i];
    }
    ll ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans-1;
}

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b){
	 if (a.first == b.first)
        return a.second < b.second;  // Si los first son iguales, ordenar por second
    return a.first < b.first;
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
   
    int n, v;
    cin >> n >> v;
    vector<ll> y, x;
    vector<pair<ll, ll>> b;
    y.push_back(0);
    x.push_back(0);
    forn(i, n){
        int p;
        cin >> p;
        y.push_back(p);
    }

    forn(i, n){
        int p;
        cin >> p;
        x.push_back(p);
    }

    forn(i, n+1){
        ll X,Y;
        X = x[i];
        Y = y[i];
        b.push_back(make_pair(v*Y + X, v*Y - X));
    }
    sort(b.begin(), b.end());
    vector<ll> aux;
    sort(b.begin(), b.end(), sortbysec);
    forn(i, n+1){
        if(b[i].first >= 0)
            aux.push_back(b[i].second);
    }
    cout << lis(aux) << endl;

    return 0;
}