#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define hola cout << "hola" << endl
#define DEBUG
#ifdef DEBUG
    #define DBG(x) x
#else
    #define DBG(x)
#endif

#define Vec(a) for(int i = 0; i < a.size(); i++){ cout << a[i] << " "; }cout << endl;
#define VecBi(a) for(int i = 0; i < a.size(); i++)  { cout << endl; for(int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";}cout << endl;

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> S(n);
    forn(i,n){
        int m;
        cin >> m;
        forn(j, m){
            int valor;
            cin >> valor;
            S[i].push_back(valor);
        }
        
    }
    VecBi(S);


   
}