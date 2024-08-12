#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);

    int a0, a1, a2, a3;
    cin >> a0 >> a1 >> a2 >> a3;

    int x = min(a0, min(a2, a3));
    int y = min(a0-x, a1);
    cout << 256 * x + 32 * y;
}