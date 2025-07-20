#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define ll long long

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    
    ll r,x,y,x2,y2;
    cin >> r >> x >> y >> x2 >> y2;

    ll cat1 = (y-y2)*(y-y2);
    ll cat2 = (x-x2)*(x-x2);
    //cout << cat1 << " " << cat2 << endl;
    double distancia = sqrtl(cat1+cat2);
    if(distancia==0){
        cout << 0 << endl;
        return 0;
    }

    
    int res=0;
    ll diametro = r*2;
    //cout << distancia << "  " << diametro << endl;
    while(distancia>0){
        distancia -= diametro;
        res++;
    }
    cout << res << endl;
    
    return 0;
}