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

double tiradas(int cant){
    int sum=0;
    forn(i,cant){
        sum += rand() % 2;
    }
    double promedio = double (sum) / double (cant);
    return promedio;
}

int main() {
    
    cout << fixed << setprecision(9) << "10 tiradas: "<< tiradas(10) << endl;
    
    cout << fixed << setprecision(9) << "100 tiradas: "<< tiradas(100) << endl;
    
    cout << fixed << setprecision(9) << "1.000 tiradas: "<< tiradas(1000) << endl;
    
    cout << fixed << setprecision(9) << "10.000 tiradas: "<< tiradas(10000) << endl;
    
    cout << fixed << setprecision(9) << "100.000 tiradas: "<< tiradas(100000) << endl;
   
    cout << fixed << setprecision(9) << "1.000.000 tiradas: "<< tiradas(1000000) << endl;
   
    cout << fixed << setprecision(9) << "10.000.000 tiradas: "<< tiradas(10000000) << endl;
   
    cout << fixed << setprecision(9) << "100.000.000 tiradas: "<< tiradas(100000000) << endl;

    return 0;
}