#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#include <math.h>


int main() {
    freopen("input.txt", "r", stdin);
   
    map<int,int> s;

    int n;
    cin >> n;
    forn(i,n){
        int valor;
        cin >> valor;
        s[valor]++;
    }
    cout << s.begin()->first << endl;
    cout << s.rbegin()->first << endl;
    return 0;
}