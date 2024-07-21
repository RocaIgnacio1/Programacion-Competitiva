#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt", "r", stdin);
    int t;

    cin >> t;
    forn(j,t){
        int sum = 0;
        int a,b,c;
        int i=0;
        bool ban = false;
        cin >> a >> b >> c;
        sum += a+b+c;
        int div = sum / 9;
        if(sum % 9 == 0 && a >= div && b >= div && c >= div){
            ban = true;
        }

        if(ban){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    

}