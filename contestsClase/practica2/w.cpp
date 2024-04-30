#include <bits/stdc++.h>
using namespace std;


int main (){
    int n, k, minutosDisp, i;
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;

    minutosDisp= 60*4;
    minutosDisp = minutosDisp - k;
    for(i=1; i<=n; i++){
        if(minutosDisp>=5*i){
            minutosDisp = minutosDisp - 5*i;
        }else{
            break;
        }
    }
    cout << i-1 << endl;

    return 0;
}