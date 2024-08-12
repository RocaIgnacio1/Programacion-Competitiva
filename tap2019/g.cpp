#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    int n;
    cin >> n;
    int p;
    cin >> p;
    vector<int> v;
    forn(j, n-1){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    if(n>1) v[0]--;
    ll acum = 0;
    for(auto j : v){
        acum += (ll)j * (ll)(n-1);
        n--;
    }
    if(acum >= p){
        cout << "NO" << endl;
    }else{
        cout << "SI" << endl;
    }

}