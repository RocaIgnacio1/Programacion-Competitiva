#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    int c = 0;
    cin >> n;

    int sum = 0;
    forn(i, n){
        int a;
        cin >> a;

        if (a % 2 == 0){
            cout << a/2 << endl;
            sum += a/2;
            continue;
        }

        int fl = floor(a*0.5);
        int ce = ceil(a*0.5);
        //cout << "ceil: " << c << "  floor: " << fl << endl;
        if (c % 2 == 0){
            cout << max(fl, ce) << endl;
            sum += max(fl,ce);
        }else{
            sum += min(fl,ce);
            cout << min(fl, ce) << endl;
        }

        c++;
    }
}