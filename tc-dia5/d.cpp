#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    ll d;
    vector<ll> dist;
    cin >> n >> d;

    forn(i,n){
        ll valor;
        cin >> valor;
        dist.push_back(valor);
    }
    ll suma=0;
    for(int i=1;i<n;i++){
        ll distancia;
        distancia = abs(dist[i] - dist[i-1]);
        
        if(distancia == 2*d){
            suma ++;
        }else{
            if(distancia >= 2*d){
                suma += 2;
            }
        }
        
    }
    cout << suma+2 << endl;
}