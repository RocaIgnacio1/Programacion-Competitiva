#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    char t[100000000];
    cin >> t;

    string respuesta;
    char anterior, actual;
    respuesta= "";
    int n;
    n = strlen(t);
    
    if (n != 1){
        for(int i = 1; i < n; i++){
            anterior = t[i-1];
            actual = t[i];
            if(actual != anterior){
                respuesta += anterior;
            }
        }
        respuesta += actual;
    } else{
        respuesta += t[0];
    }
    
    
    //cout << respuesta.length() << endl;
    
    if ( respuesta.length() < 2){
        cout << respuesta << endl;
    }
    else if (respuesta[0]=='1')
    {
        if(respuesta[respuesta.length()-1]=='1'){
            cout << "101" << endl;
        }
        else{
            cout << "10" << endl;
        }
    }else if (respuesta[0]=='0')
    {
        if(respuesta[respuesta.length()-1]=='1'){
            cout << "01" << endl;
        }
        else{
            cout << "010" << endl;
        }
    }
      
    return 0;
}
