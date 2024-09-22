#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    
    string p1,p2,p3,p4,p5;
    int a,b,c,d,e;

    p1 = "1 1 1";
    p2 = "0 1 1";
    p3 = "0 1 1";
    p4 = "1 0 0";
    p5 = "1 0 0";

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

    int x1,x2,x3;
    if (a==b+d){

        if (e+b==a){
            /* c miente */
            
            x3=1;
            cout << a-b << " " << b-x3 << " " << x3 << endl;

        } else{
            /* e miente */
            x3=1;
            cout << a-b << " " << b-x3 << " " << x3 << endl;
        }
    } else{

        if (e+c==a){
            if(e+b==a){

                /* d miente */
                x3=1;
                cout << a-b << " " << b-x3 << " " << x3 << endl;

            } else{

                /* b miente */
                x3=1;
                cout << a-c << " " << c-x3 << " " << x3 << endl;
            }
        }else{

            /* a miente */
            x3=1;
            cout << d << " " << c-x3 << " " << x3 << endl;
            
        }


    }
     
    
    
    
      
    return 0;
}
