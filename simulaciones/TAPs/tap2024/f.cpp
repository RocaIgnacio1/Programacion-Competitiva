#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)

#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int con = 0, res = 0, con2 = 0;
    forn(j, n){
        int p;
        cin >> p;
        con++;
        if(p == 1){
            res++;
            con2++;
        }else{
            res --;
            con2 = 0;
        }
        if(con2 >= 3){
            res += 1;
        }

    }
    cout << res << endl;
}
