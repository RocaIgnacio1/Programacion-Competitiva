#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    map<int,int> a;

    forn(i,n){
        int p;
        cin >> p;
        a[p]++;
    }

    if(n==1){
        cout << "N" << endl;
        return 0;
    }

    if(n==2){
        cout << "Y" << endl;
        return 0;
    }

   

    forn(i,1000000){
        if(a.find(i) != a.end()){
            int valor = a[i];
            if(valor==1)continue;
            if(valor%2==0){
                a[i+1] += valor/2;
                a.erase(i);
            }else{
                a[i] = 1;
                a[i+1] += valor/2;
            }
        }
    }

    if(a.size()==2 || a.size()==1){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
    
    return 0;
}
