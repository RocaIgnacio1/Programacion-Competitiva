#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt", "r", stdin);
    string carta;
    cin >> carta;
    bool ban=false;
    forn(i,5){
        string c;
       cin >> c;
       if((carta[0]==c[0]) ||  (carta[1]==c[1])   ) {
        ban=true;
       }
    }
    
    if (ban){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    

}