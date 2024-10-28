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
    vector<ll> k(n);
    forn(i,n){
        cin >> k[i];
    }
    int ans=0;
    map<ll,ll> aux;
    int count=0, desde=0;
    forn(i,n){
        if(i==0 ||  aux.find(k[i])==aux.end() || aux[k[i]]<desde){
            count++;
        }else{
            desde=aux[k[i]]+1;
            count= i- aux[k[i]];
        }
        aux[k[i]]=i;
        ans = max(ans,count);
    }
    cout << ans << endl;
    return 0;
}
