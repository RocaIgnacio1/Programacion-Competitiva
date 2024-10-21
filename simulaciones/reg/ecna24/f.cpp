#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
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
    
int comp(string s){
    reverse(s.begin(), s.end());
    __int128_t prod = 1;
    __int128_t res = 0;
    //ll res = 0;
    forn(i, s.size()){
        res += (((__int128_t)(s[i] - '0')) * prod);
        prod*=10;
    }
    int con = 0;
    while(res > 1){
        res/=2;
        con++;
    }
    return con;
}

string s;
void g(__int128_t x) {
    if(x==0) return;
    s.push_back(x%10+'0');
    g(x/10);
}

__int128_t elevar(int n){
    __int128_t res = 1;
    forn(i, n) res*=2;
    return res;
}
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    vector<int> v;
    cin >> n;
    forn(i, n){
        string p;
        cin >> p;
        v.push_back(comp(p));
    }  
    forn(i,128){
        if(v.size()==1){    
            g(elevar(v[0]));
            reverse(s.begin(), s.end());
            cout << s << endl;
            return 0;
        }
        vector<int> v2;
        forn(j,v.size()){
            if(j!=v.size()-1 && v[j]==i && v[j+1]==i){
                v2.pb(v[j]+1);
                j++;
            }else{
                if(v[j]!=i){
                    v2.pb(v[j]);
                }
            }
        }

        v=v2;
    }
}