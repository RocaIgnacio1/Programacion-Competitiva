#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    //freopen("input.txt", "r", stdin);
    int n,k;
    cin >> n >> k;
    map<char,int> p;

    forn(i,n){
        char valor;
        cin >> valor;
        p[valor]++;
    }
    int minimo = 1000000;
    if(p.size()<k){
        cout << 0 << endl;
    }else{
        
        for(const auto& pair: p ){
            
            minimo = min(pair.second, minimo);
        }
        cout << minimo*k << endl;
    }
    
    
}