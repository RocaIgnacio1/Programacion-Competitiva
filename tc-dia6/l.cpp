#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    //freopen("input.txt", "r", stdin);
    int n,x;
    cin >> n >> x;
    int p = n-1;
    //cout << x << " " << p << endl;
    if(x > p){
        //cout << "hola" << endl;
        cout << -1 << endl;
        return 0;
    }else{

    

    vector<vector<int>> dogs(n);
    int valor=1;
    forn(i,n){
        forn(j,x){
            dogs[i].push_back(valor);
            valor++;
        }
        
    }

    forn(i,n){
        forn(j,x){
            int valor = dogs[i][j];
            //cout << i+j+1%n << " " << valor << endl;
            dogs[((i+j+1)%n)].push_back(valor);
        }
    }



    forn(i,n){
        forn(j,2*x){
            cout << dogs[i][j] << " ";
        }
        cout << endl;
    }
    }
}