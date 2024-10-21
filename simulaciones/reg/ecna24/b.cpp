#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int m,n,k,s;
    cin >> m >> n >> k >> s;
    vector<double> p;
    forn(i,m){
        double a;
        cin >> a;
        p.pb(a);
    }
    forn(i,n){
        double a;
        cin >> a;
        p.pb(a);
    }
    
    sort(p.begin(),p.end());

    vector<pair<double,int>> espacios;
    forn(i,m+n-1){
        espacios.pb(make_pair(p[i+1]-p[i],i));
    }
  
    sort(espacios.begin(),espacios.end());
    reverse(espacios.begin(),espacios.end());
    vector<double> separador;
    forn(i,k-1){
        separador.pb(espacios[i].second+1);
    }
    separador.pb(p.size()+1);

    double altura = double(s)/2;
    altura = altura*altura;

    vector<double> wifi;
    int j=0, cant=0;
    double sum=0;
    forn(i,p.size()){
        if(i<separador[j]){
            cant++;
            sum+=p[i];
        }else{
            wifi.pb(double(sum/cant));
            j++;
            sum=p[i];
            cant=1;
        }
    }
    wifi.pb(double(sum/cant));
    j=0;
    double ans=0;
    forn(i,p.size()){
        if(i<separador[j]){ 
            double cateto = abs(wifi[j]-p[i])*abs(wifi[j]-p[i]);
            double calculo = double (cateto+altura);
            ans += calculo;
        }else{
            j++;
            double cateto = abs(wifi[j]-p[i])*abs(wifi[j]-p[i]);
            double calculo = double (cateto+altura);
            ans += calculo;
        }
        
    }
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}