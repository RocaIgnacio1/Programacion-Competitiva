#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";
#define ll long long
#define ld double
#define pb push_back
 
int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    forn(w,t){
        int l=2,r=999,mid=0;
        mid=(l+r) / 2;
        while(l!=mid && l<=r){
            int salida;
            mid=(l+r) / 2;
            cout << "?" << " " << l << " " << mid << endl;
            cin >> salida;
            
            if(salida==l*mid){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout << "! " << l << endl;
        cout.flush();
    }
    return 0;
}