#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t, n, num;
    //freopen("input.txt", "r", stdin);
    cin >> t;

    for(int i = 0; i<t;i++){
        int n;
        cin >> n;
        ll sum = 0;
        for (int j = 0; j<n; j++){
            int num;
            cin >> num;
            sum = sum + num;
        }
        ll raiz = 0;
        raiz = sqrt(sum);
        if( raiz * raiz == sum){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        


    }
    return 0;
}