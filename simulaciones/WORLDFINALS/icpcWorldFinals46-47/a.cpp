#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    
    string p1,p2,p3,p4,p5;
    int a,b,c,d,e;

    p1 = "0 0 1";
    p2 = "1 1 0";
    p3 = "0 1 1";
    p4 = "1 0 1";
    p5 = "0 1 0";

    cout << p1 << endl; 
    cin >> a ;
    cout << p2 << endl;
    cin >> b ;
    cout << p3 << endl;
    cin >> c ;
    cout << p4 << endl;
    cin >> d ;
    cout << p5 << endl;
    cin >> e ;


    if ( a+b == d + e){
        cout << b-e << " " << e << " " << a << endl;
    }
    else if (a+e == c)
    {
        if( abs(a+b-c) == 2*a){
            cout << a+b-c << " " << e << " " << a << endl;
        }
        else{ 
            cout << d+e-c << " " << e << " " << a << endl;
        }
    } 
    else 
    {
        if( abs(b+c-d) == 2*e){
            cout << b-e << " " << e << " " << d+e-b << endl;
        }
        else{
            cout << b+a-c << " " << b+a-d << " " << a << endl;
        }
    }
    
    
    
    
    
      
    return 0;
}
