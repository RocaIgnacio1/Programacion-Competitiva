#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,h,w;
    cin >> n >> h >> w;
    vector<char> casa;
    vector<char> work;
    forn(i,n){
        char a,b;
        cin >> a >> b;
        casa.pb(a);
        work.pb(b);
    }
    
    forn(i,n){
        
        if((casa[i]=='Y' && h>0) || (h>0 && w==0)){
            cout << "Y" << " ";
            h--;
            w++;
        }else{
            cout << "N" << " ";
        }

        if((work[i]=='Y' && w>0) || (w>0 && h==0)){
            cout << "Y" << " ";
            w--;
            h++;
        }else{
            cout << "N" << " ";
        }

        cout << endl;
    }


    return 0;
}