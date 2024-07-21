#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //  freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    forn(i, t){
        ll n;
        cin >> n;
        int count = 0;

        for(ll j=1; j<=32000; j++){
            ll cuad = j*j;
            ll cub = cuad*j;

            //cout << cuad << " " << cub << endl;

            if ((n >= cuad)){
                count ++;
            }
            if ((n >= cub)){
                count ++;
            }
        }

        for(ll j=1;j<=33;j++){
            ll cuad = j*j*j*j*j*j;

            if ((n >= cuad)){
                count --;
            }
        }
     
        cout << count << endl;
    }
}