#include <bits/stdc++.h>
using namespace std;
int main () {
    vector<int> dias = {1,2,3,4,5,6,7};
    vector<bool> mask(dias.size(), false);
    //combinaciones de D elementos.
    int d = 3;
    fill(mask.begin(), mask.begin() + d, true); //1110000
   
    do {
        for (int i = 0; i < dias.size(); ++i) {
            if (mask[i]) {
                // permutacion actual
                cout << dias[i] << " ";
            }
        }
        cout << endl;
    } while (prev_permutation(mask.begin(), mask.end()));

    /* Salida
        1 2 3 
        1 2 4 
        1 2 5
        1 2 6
        1 2 7
        1 3 4
        1 3 5
        1 3 6
        1 3 7
        ..
        5 6 7
    */
  return 0;
}