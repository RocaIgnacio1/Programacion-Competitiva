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

int main() {
    HOLA;
    #ifdef EBUG
    freopen("a.txt", "r", stdin);
    #endif


    int t;
    cin >> t;
    forn(i,t){
        ll a,b,c,l,r;
        cin >> a >> b >> c >> l >> r;

        vector<int> ceros;
        for(int i=l; i<=r; i++){
            if(i*i*a+i*b+c==0)ceros.push_back(i);
        }

        if(ceros.size()==0){
            // a pelo
            ll vall = 2*a*l*l*l + 3*b*l*l + 6*c*l;
            ll valr = 2*a*r*r*r + 3*b*r*r + 6*c*r;
            ll nom = abs(vall-valr);
            ll gcd = __gcd(nom, (ll)6);
            cout << nom/gcd << "/" << 6/gcd << endl;
            continue;
        }

        if(ceros.size()==1){
            ll c1 = ceros[0];
            ll val1 = 2*a*l*l*l + 3*b*l*l + 6*c*l;
            ll val2 = 2*a*c1*c1*c1 + 3*b*c1*c1 + 6*c*c1;
            ll val3 = 2*a*r*r*r + 3*b*r*r + 6*c*r;


            ll nom = abs(val1-val2) + abs(val2 - val3);
            ll gcd = __gcd(nom, (ll)6);
            cout << nom/gcd << "/" << 6/gcd << endl;
            continue;
        }

         if(ceros.size()==2){
            ll c1 = ceros[0];
            ll c2 = ceros[1];
            ll val1 = 2*a*l*l*l + 3*b*l*l + 6*c*l;
            ll val2 = 2*a*c1*c1*c1 + 3*b*c1*c1 + 6*c*c1;
            ll val3 = 2*a*c2*c2*c2 + 3*b*c2*c2 + 6*c*c2;
            ll val4 = 2*a*r*r*r + 3*b*r*r + 6*c*r;


            ll nom = abs(val1-val2) + abs(val2 - val3) + abs(val3 - val4);
            ll gcd = __gcd(nom, (ll)6);
            cout << nom/gcd << "/" << 6/gcd << endl;
            continue;
        }
        cout << endl;
    }
    
    return 0;
}