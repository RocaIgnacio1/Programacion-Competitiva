#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)



int main(){
    //freopen("input.txt","r",stdin);
    ll D, M, D1, N, D2;
    cin >> D >> M >> D1 >> N >> D2;
    vector<ll> prefixPow;
    
    // no llega D1
    if(D1<D){
        cout << -1 << endl;
        return 0;
    }
    forn(i,M){
        D = D-(D1-D);
        if(D<=0){
            cout << i+1 << endl;
            return 0;
        }
    }
   
    //no llega D2
    if(D2<D){
        cout << -1 << endl;
        return 0;
    }

    prefixPow.push_back(D2-D);
    for(int i=1;i<150;i++){
        prefixPow.push_back((prefixPow[i-1]*2 + (D2-D)));
    }
    
    forn(i,150){
        //cout <<prefixPow[i] << " " << D<< " " << i+1+N << endl;
        if(prefixPow[i]>=D && i+1<=N){
            cout << i+1+M << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
}