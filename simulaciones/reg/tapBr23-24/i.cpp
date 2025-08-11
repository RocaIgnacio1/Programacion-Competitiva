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
    freopen("input.txt", "r", stdin);
    #endif

    int n, unos=0;
    cin >> n;
    vector<ll> a(n);
    forn(i,n){
        cin >> a[i]; 
        if(a[i]==1)unos++;
    }
    ll ans=0;

    vector<ll> izq, der;
    int suma=0;
    forn(i,n){
        if(a[i]==1){
            izq.push_back(suma);
            suma=0;
        }else{
            suma++;
        }
    }
    suma=0;

    dforn(i,n){
        if(a[i]==1){
            der.push_back(suma);
            suma=0;
        }else{
            suma++;
        }
    }

    forn(i,izq.size()){
        //cout << izq[i] << " ";
    }
    forn(i,der.size()){
        //cout << der[i] << " ";
    }

    forn(i,unos){
        //cout << endl << ((unos-(i+1))/2)+1 << "  " << (izq[i]+1) << endl;
        ans += (((unos-(i+1))/2)+1 )*(izq[i]+1);
    }
    //cout << endl << ans << endl;
    
    forn(i,unos){
        //if(der[i]==0)continue;
        //cout << endl << ((unos-(i+1))/2)+1 << "  " << der[i] << endl;
        ans += (((i/2)+1)*(der[i]+1)) ; 
    }
    if(unos!=1){
        ans-=unos;
        ans-=(unos-1);
    }
    cout <<  ans << endl;
    
    return 0;
}