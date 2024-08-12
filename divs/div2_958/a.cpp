#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#include <math.h>


int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    forn(i,t){
        int n,k;
        cin >> n >> k;
        int res=0;
        if(n==1){
            cout << 0 << endl;
        }else{

            if(n<=k){
                cout << 1 << endl;
            }else{
                int i=0;
                while(n>1){
                    n = n-(k-1);
                    i++;
                }
                cout << i << endl;
            }
            

        }
    }
}