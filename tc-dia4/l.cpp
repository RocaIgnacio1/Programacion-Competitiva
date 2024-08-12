#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
 
int main(){
    //freopen("input.txt", "r", stdin);
    int x,y,z, a,b,c;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
 
    int suma = 0;
    int necesita=0;
    
    if(a>x){
        suma += ((a-x)/2);
    }else{
        necesita += (x-a);
    }
 
    if(b>y){
        suma += ((b-y)/2);
    }else{
        necesita += (y-b);
    }
 
    if(c>z){
        suma += ((c-z)/2);
    }else{
        necesita += (z-c);
    }
 
 
    if(suma>=necesita){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
 
 
 
    return 0;
}