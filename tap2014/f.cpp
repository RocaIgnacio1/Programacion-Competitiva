#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin); 

    int n, t;
    cin >> n >> t; 

    vector<tuple<int, string>> jardin(n);

    for (int i = 0; i < n; i++) {
        jardin[i] = make_tuple(i, "");
    }

    for (int i = 0; i < t; i++) {
        int sacar, mirar;
        string poner;
        cin >> sacar >> poner >> mirar; 

        for (int j = 0; j < n; j++) {
            // sacar
            string a = get<1>(jardin[j]);
            int longitud = a.size();
            jardin[j] = make_tuple(get<0>(jardin[j]), a.substr(0, longitud - sacar)); 

            // poner
            string b = get<1>(jardin[j]) + poner[j];  
            jardin[j] = make_tuple(get<0>(jardin[j]), b);
        }

        vector<tuple<int, string>> copia = jardin;

        sort(copia.begin(), copia.end(), [](const tuple<int, string>& a, const tuple<int, string>& b) {
            return get<1>(a) < get<1>(b);
        });

        int ans = get<0>(copia[mirar - 1]) + 1; 
        cout << ans << endl;
    }

    return 0;
}
