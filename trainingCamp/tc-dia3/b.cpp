#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = (a+b+c+d);
    if(a * 2 == sum || b * 2 == sum || c * 2 == sum || d * 2 == sum){
        cout << "YES" << endl;
        return 0;
    }
    if((a+b) * 2 == sum || (a+c) * 2 == sum || (a+d) * 2 == sum || (b+c) * 2 == sum || (b+d) * 2 == sum || (c+d) * 2 == sum){
        cout << "YES" << endl;
        return 0;
    }
    if((a+b+c) * 2 == sum || (a+b+d) * 2 == sum || (b+c+d) * 2 == sum || (a+c+d) * 2 == sum){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
}