#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
vector<int> dp;

int main(){
    //freopen("input.txt", "r", stdin);
    int t, a, b;
    cin >> t;
    forn(i,t){
        cin >> a >> b;

        cout << a*b << endl;
    }
    return 0;
}