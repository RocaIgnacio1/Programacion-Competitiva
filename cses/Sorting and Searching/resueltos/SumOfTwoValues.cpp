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



int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> p;
    vector<ll> aux;

    forn(i,n){
        ll num;
        cin >> num;
        aux.push_back(num);
        p.push_back(num);
    }
    sort(p.begin(),p.end());
    ll a=0,b=0;
    bool ban=false;
    int limite=n-1;
    for(int i=0; i<n; i++){
        if(ban)break;
        if(p[i]>=x)break;
        for(int j=limite; j>i; j--){
            if(p[i]+p[j]==x){
                a=p[i];
                b=p[j];
                ban=true;
                break;
            }else{
                if(p[i]+p[j]<x){
                    limite=j;
                    break;
                }
            }
        }
    }

    if(a==0&&b==0)cout << "IMPOSSIBLE" << endl;
    else{
        int indiceA=0, indiceB=0;
        forn(i,n){
            if(aux[i]==a){
                indiceA=i;
                break;
            }
        }
        forn(i,n){
            if(aux[i]==b && i!=indiceA){
                indiceB=i;
                break;
            }
        }
        indiceA++;
        indiceB++;
        if(indiceA<indiceB) cout << indiceA << " " << indiceB << endl;
        else cout << indiceB << " " << indiceA << endl;
        
    }
    
}