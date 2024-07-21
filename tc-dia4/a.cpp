#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    forn(i,t){
        int a, b, c, x ,y;
        cin >> a >> b >> c >> x >> y;

        if(c>= (max((x-a),0)+max((y-b),0))){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    

}