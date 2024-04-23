#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main () {

    int t;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    
    for(int i=0; i<t; i++){
        
        int n, s, num;
        cin >> n >> s;
     
        vector<int> a = {};
        vector<int> b = {};
        vector<int> a_costo = {};
        vector<int> b_costo = {};    

        int cant_unos = 0;
        for(int j=0; j<n; j++){
            cin >> num;
            a.push_back(num);
            if(num==1){
                cant_unos++;
            }
        }
        
        b = a;
        reverse(b.begin(),b.end());
        
        int contador = 0;
        // esfuerzo para sacar cada 1
        for(int i = 0; i< a.size(); i++){
            contador++;
            if(a[i] == 1){
                a_costo.push_back(contador);
            }
        }

        contador = 0;
        // esfuerzo para sacar cada 1
        for(int i = 0; i< b.size(); i++){
            contador++;
            if(b[i] == 1){
                b_costo.push_back(contador);
            }
        }

        int min;
        if(cant_unos == s){
            // no hay que sacar unos.
            cout << 0 << endl;
        }else{
            if(cant_unos < s){
                // no hay unos para sacar.
                cout << -1 << endl;
            }else{

                // sacando todo de un lado o todo del otro
                if(b_costo[cant_unos-s-1]< a_costo[cant_unos-s-1]){
                    min = b_costo[cant_unos-s-1];
                }else{
                    min = a_costo[cant_unos-s-1];
                }

                // sacando de ambos lados
                for(int j=0; j < cant_unos-s-1; j++) {
                    if (a_costo[j] + b_costo[cant_unos-s-j-2] < min){
                        min = a_costo[j] + b_costo[cant_unos-s-j-2];
                    }
                }

                cout << min << endl;

            }
        }
        


    }
    return 0;
}
