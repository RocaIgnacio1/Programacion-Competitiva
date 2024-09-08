#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
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

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<int> x(n);
    forn(i,n){
        cin >> x[i];
    }
    vector<int> indice(n+1);
    
    forn(i,n){
        indice[x[i]]=i;
    }
    int rondas=1;
    forn(i,n){
        if(indice[i]>indice[i+1]){
            rondas++;
        }
    }
    cout << rondas << endl; 
    
    return 0;
}
