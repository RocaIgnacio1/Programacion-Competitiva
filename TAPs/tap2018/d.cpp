#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    int N, M;
    cin >> N >> M;
    double a=0.5;
    double res = (double)((double)M-1) + (double)(N-M+1)*a;
    cout << fixed << setprecision(1) << res << endl;
}