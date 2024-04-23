#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main () {

    int t;
    freopen("input.txt", "r", stdin);
    cin >> t;
    
    for(int i=0; i<t; i++){
        
        int n, s, contador=0, num;
        cin >> n >> s;
        int cant = n - s;
        vector<int> a = {};
        vector<int> b = {};
        vector<int> ax = {};
        vector<int> bx = {};

        for(int j=0; j<n; j++){
            cin >> num;

            if(num==1){
                a.push_back(contador);
                contador=0;
            }else{
                contador++;
            }       
        }
        a.push_back(contador);
        b = a;
        reverse(b.begin(),b.end());

        int sum = 0;
        for(int j=0; j< b.size(); j++){
            sum = sum + b[j];
            bx.push_back(sum);
        }
        sum = 0;
        for(int j=0; j< a.size(); j++){
            sum = sum + a[j];
            ax.push_back(sum);
        }
        cant = a.size() - s - 1;
        if(cant < 0){
            cout <<  -1 << endl;
        }else{
            if (cant == 0){
                cout <<  0 << endl;
            } else {
                int min = ax[cant - 1];
                for(int j=0; j < cant - 1; j++) {
                    if (ax[j] + bx[cant-j-2] < min){
                        min = ax[j] + bx[cant-j-2];
                    }
                }
                if(bx[cant]< min){
                    min = bx[cant];
                }


                cout << min + cant << endl;
            }
        }
        
    }
    return 0;
}
