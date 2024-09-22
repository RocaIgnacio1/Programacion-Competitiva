#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    if(a>=b+c){
        cout << "S" << endl;
        return 0;
    }

    if(b>=a+c){
        cout << "S" << endl;
        return 0;
    }

    if(c>=b+a){
        cout << "S" << endl;
        return 0;
    }
    cout << "N" << endl;
}
