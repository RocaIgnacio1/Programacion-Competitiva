#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int potencia(int n){ //devuelve el menor valor posible potencia de 2 de n
    if(n == 1) return 1;
    int pow = 1;
    while((ll)pow*2<= (ll)n){
        pow *= 2;
    }
    return pow;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n,k;
    cin >> n >> k;
    int aux = n;
    int con = 0;
    vector<int> v, arr;
    while(aux != 0){
        con ++;
        int p = potencia(aux);
        aux -= p;
        v.push_back(p);
    }

    if(con > k || k > n){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        int it = 0;
        while(con < k){
            if(v[it] != 1){
                int a = v[it]/2;
                v[it] = a;
                v.push_back(a);
                con++;
            }else{
                it++;
            }
        }
        forn(i, v.size()){
            cout << v[i] << " ";
        }
    }

    

}