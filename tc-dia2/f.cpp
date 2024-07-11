#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i < 1; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    forn(K, t){
        vector<ll> P, N;
        int k, n;
        cin >> k >> n;
        forn(i, k){
            ll j;
            cin >> j;
            if(j > 0){
                P.push_back(j);
            }else{
                N.push_back(llabs(j));
            }
        }
        sort(P.begin(), P.end());
        sort(N.begin(), N.end());
        ll res;
        if(N.empty()){
            res = P[P.size()-1];
        }else if(P.empty()){
            res = N[N.size()-1];
        }else{
            res = max(P[P.size()-1], N[N.size()-1]);
        }
        int con = n;
        ll sum = 0;
        for(int i = 0; !P.empty(); i++){
            if(con == n){
                con = 0;
                sum += P[P.size() - 1];
            }
            con ++;
            P.pop_back();
        }
        con = n;
        for(int i = 0; !N.empty(); i++){
            if(con == n){
                con = 0;
                sum += N[N.size() - 1];
            }
            N.pop_back();
            con ++;
        }
        cout << (sum * 2) - res<< endl;


    }
    return 0;
}