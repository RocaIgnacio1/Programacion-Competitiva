#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {

    ll n, d;
    cin >> n >> d;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    ll contador = 0;
    ll j= 0;
    for(ll i=0; i<n; i++){
        
        while ( a[i] - a[j] > d){
            j++;
        }
        contador = contador + ((i-j)* (i-j-1)/2);
    }

    cout << contador << endl;
    return 0;
}

