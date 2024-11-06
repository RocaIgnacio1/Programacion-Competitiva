#include <bits/stdc++.h>
using namespace std;
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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    
    int k,n;
    cin >> k >> n;
    map<int,int> s;
    forn(i,n){
        int a;
        cin >> a;
        s[a]++;
    }
    int cant=0;
    if((n+1) % k == 0){
        cant = (n+1)/k;
    }else{
        if((n-1)%k==0){
            cant = (n-1)/k;
        }else{
            if(n%k!=0){
                cout << "*" << endl;
                return 0;
            }else{
                cant = n/k;
            }
        }
    }
    vector<int> res;
    for(int i=1; i<k+1; i++){
        if(s[i]==cant)continue;
        if(s[i]>cant+1 || s[i]<cant-1){
            cout << "*" << endl;
            return 0;
        }
        if(s[i]<cant){
            res.push_back(i);
        }else{
            res.push_back(-i);
        }
    }

    if(res.size()>1){
        if(res[0]<0){
            cout << "-" << -res[0] << " " << "+" << res[1] << endl;
        }else{
            cout << "-" << -res[1] << " " << "+" << res[0] << endl;
        }
    }else{
        if(res[0]<0){
            cout << "-" << -res[0] << endl;
        }else{
            cout << "+" << res[0] << endl;
        }
        
    }
    
    return 0;
}