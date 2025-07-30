#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; 
    cin >> n;
    vector<long long> divisores;
    for(long long i = 1; i*i <= n; ++i){
        if(n % i == 0){
            divisores.push_back(i);
            if(i != n / i) divisores.push_back(n / i);
        }
    }
    sort(divisores.begin(), divisores.end());
    for(long long d : divisores){
        cout << d << " ";
    }
    cout << "\n";
    return 0;
}
