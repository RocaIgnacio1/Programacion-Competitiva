#include <bits/stdc++.h>
using namespace std;

int t, m;
vector<char> combinacion(8,' ');

bool balanced(int exp, int n) {
    if (exp == 8) {
        return n==0;
    }

    combinacion[exp] = '+';
    if (balanced(exp + 1, n - pow(3, exp))) return true;
    

    combinacion[exp] = '0';
    if (balanced(exp + 1, n)) return true;

    combinacion[exp] = '-';
    if (balanced(exp + 1, n + pow(3, exp))) return true;

    return false;
}

int main() {
    int n;

    int t;
    cin >> t;
    for(int w=0; w<t; w++){
        cin >> n;
    
        balanced(0,n);
        bool bandera = true;

        for (int i =7; i>=0; i--) {
            if(bandera && combinacion[i]=='0'){
                continue;
            }
            if(combinacion[i] == '+' || combinacion[i] == '-'){
                bandera = false;
            }
            cout << combinacion[i];
        }
        cout << endl;
    }

    return 0;
}
