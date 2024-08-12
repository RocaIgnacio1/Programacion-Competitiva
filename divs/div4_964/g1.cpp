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
        int l=1,r=999;
        while(r-l>2){
            int mid1 = (2 * l + r) / 3;
            int mid2 = (2 * r + l) / 3;
            int salida;
            //cout << (mid1+1)*(mid2+1) << endl;
            cout << "?" << " " << mid1 << " " << mid2 << endl;
            cin >> salida;
            if(salida==(mid1+1)*(mid2+1)){
                //izq
                r=mid1;
            }else{
                if(salida==(mid1)*(mid2+1)){
                    //centro
                    l=mid1;
                    r=mid2;
                }else{
                    if(salida==(mid1*mid2)){
                        //der
                        l=mid2;
                    }
                }
            }
        }
        if (r - l == 2) {
            cout << "? 1 " << l + 1 << endl;
            int salida; cin >> salida;
            
            if (salida == l + 1) {l = l + 1;}
            else {r = l + 1;}
            
        }
        cout << "! " << r << endl;
        
        //cout.flush();
    }
    return 0;
}