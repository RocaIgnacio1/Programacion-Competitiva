#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i < 1; i--)

vector<vector<int>> v;

int main(){
ll n, d, e;
cin >> n;
cin >> d;
cin >> e;
e = 5 * e;
ll acum = 0;
ll min = 10000000000;
for(int i = 0; acum <= n; i++){
    ll res = (n - acum) % d; 
    if(res < min){
        min = res;
    }
    acum += e;
}
acum = 0;
for(int i = 0; acum <= n; i++){
    ll res = (n - acum) % e;
    if(res < min){
        min = res;
    }
    acum += d;
}
cout << min;
return 0;
}