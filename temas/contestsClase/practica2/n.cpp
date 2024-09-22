#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool fibonacciInversa(int izquierda, int derecha, int  k){
    int contador = 0;
    while( (contador < k-2) && (izquierda >= 0) && (derecha >= 0) ){
        int auxiliar;
        
        auxiliar = izquierda;
        izquierda = derecha - izquierda;
        derecha = auxiliar;
        contador++;
    }

    if ((contador == k-2) && (izquierda >= 0) && (derecha >= 0) && (derecha>=izquierda)){
        //cout << izquierda << " " << derecha << endl;
        return true;
    } else {
        return false;
    }
}

int main () {
    int t;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    
    for(int j=0; j<t; j++){
        int n, k;
        cin >> n >> k;

        int rta=0,i;

        if(n%2==0)i=n/2;
        else i=(n/2)+1;

        
        for(i ; i<=n ; i++){
            if (fibonacciInversa(i,n,k)) rta++;
        }
        
        cout << rta << endl;
    }
    return 0;
}
