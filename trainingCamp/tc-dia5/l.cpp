#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int n, ax, bx, cx, ay, by, cy;
bool solve(){
    if(cx > ax && bx < ax) return false;
    if(cx < ax && bx > ax) return false;
    if(cy > ay && by < ay) return false;
    if(cy < ay && by > ay) return false;
    return true;
}
int main(){
    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    if(solve()){
        cout << "YES";
    }else{
        cout << "NO";
    }
}