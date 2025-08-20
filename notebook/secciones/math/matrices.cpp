#include <bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define forn(i, n) forr(i,0,n)
#define dforn(i, n) for(int i= (n) -1; i >= 0; i--)
using namespace std;
typedef long long ll;
int MOD = 1000000007;
#define tipo vector<vector<ll>>
#define mult(a, b) multMat(a, b)


// Multiplicacion de matrices
// tamaño(a) = ixj tamaño(b) = jxk
vector<vector<ll>> multMat(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector<vector<ll>> ret(a.size(), vector<ll>(b[0].size())); 
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] % MOD) % MOD; 
            } 
        } 
    }
    return ret; 
}

//no eleva a la 0
tipo binExpo(tipo &a, ll n){
    n--;
    tipo res = a;
    while (n > 0) {
        if (n & 1) res = mult(res, a);
        a = mult(a, a);
        n >>= 1;
    }
    return res;
}

vector<vector<ll>> dataInput(vector<ll> &a){
    vector<vector<ll>> res;
    res.assign(a.size(), vector<ll>(a.size()));
    forn(i, a.size()-1){
        res[i][i+1] = 1;
    }
    res[a.size()-1] = a;
    return res;
} 
/*
carga de datos de ej:
si f(x) = 4f(x-1) + 5f(x-2) -2f(x-3)
A = |0  1  0|
    |0  0  1|
    |4  5 -2|
a dataInput se le pasa {4, 5, -2} y te devuelve A
y despues se multiplican por los casos bases
*/


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
    // Ejemplo: fibonacci
    vector<ll> mat = {1, 1}, base = {0,1};
    vector<vector<ll>> A, B, aux, solve;
    B.assign(base.size(), vector<ll>(1));
    B[0] = base;
    A = dataInput(mat);
    aux = binExpo(A, 6);
    solve = multMat(aux, B);
    cout << solve[0][base.size()-1] << endl;
}