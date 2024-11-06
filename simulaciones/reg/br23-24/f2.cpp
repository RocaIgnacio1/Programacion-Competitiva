#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
typedef long long ll;

using namespace std;
#define MAXP 1000000  // no necesariamente primo
vector<ll> divisores;

void obtenerDivisores(ll numero) {

    for (ll i = 1; i*i <= numero; ++i) {
        if (numero % i == 0) {
            //divisores.push_back(i);
            if (i != numero / i) {
                divisores.push_back(numero / (ll)i);
            }
        }
    }
}

bool esPalindromo(deque<ll> d){
    while(!d.empty()){
        if(d[0] != d[d.size()-1]){
            return false;
        }
        d.pop_back();
        if(!d.empty())d.pop_front();
    }
    return true;
}

deque<ll> baseb(ll n, ll b){
    deque<ll> d;
    while(n > 0){
        d.push_back(n%b);
        n/=b;
    }
    return d;
}

int main(){
    ll n;
    cin >> n;
    if(n == 2){
        cout << "*" << endl;
        return 0;
    }
    for(ll i = 2; i*i <= n; i++){
        if(esPalindromo(baseb(n, i))){
            cout << i << endl;
        }
    }
    obtenerDivisores(n);
    sort(divisores.begin(), divisores.end());
    for(auto a : divisores){
        if(esPalindromo(baseb(n, a-1))){
            cout << a-1 << endl;
        }
    }
}