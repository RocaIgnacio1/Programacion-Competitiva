#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif



int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<int> a;
    forn(i,n){
        a.pb(i+1);
    }
    vector<int> b=a;
    while(b.size()>0){
        vector<int> aux;
        if(b.size()%2!=0 && b.size()!=1)aux.pb(b[b.size()-1]);
        forn(i,b.size()){
            if(b.size()==1){
                cout << b[0];
                break;
            }
            if((i+1)%2==0){
                cout << b[i] << " ";
            }else{
                if(b.size()%2!=0 && i==b.size()-1){}
                else aux.pb(b[i]);
            }
        }

        b=aux;
    }   
    cout << endl;
    return 0;
}