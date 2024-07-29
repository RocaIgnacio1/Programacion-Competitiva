#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a; 
        bool isZero = true;
        ll suma = 0;
        ll cero=0, dos=0, cuatro=0, seis=0,ocho=0;
        for(char c : a) {          
            int p = c - '0';
            suma += p;  
            
            if(p!=0){
                isZero = false;
            }
            if(p==0) cero++;
            if(p==2) dos++;
            if(p==4) cuatro++;
            if(p==6) seis++;
            if(p==8) ocho++;
        
        }
        bool mult3 = (suma%3==0);
        bool mult4 = ((cero>0) && (cuatro>0 || ocho>0 || seis>0 || dos>0));

        if( (mult3 && mult4)|| isZero || (cero>=2 && mult3)){
            cout << "red" << endl;
        }else{
            cout << "cyan" << endl;
        }
    }
    return 0;
}
