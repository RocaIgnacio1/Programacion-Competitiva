#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back

int main() {
    int n;
    cin >> n; 
    vector<int> a;

    forn(i, n){
        a.push_back(i+1);
    }
    n--;

    forn(j, n-1){
        forn(i, n){
            a[i+1] = a[i+1] + a[i];
        }
    }
    cout << a[n] << endl;
    return 0;
}
