#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

string u, v, uaux, vaux;
#ifdef EBUG
//local
#else
//judge
#endif

string solve(string s){
    string res;
    int con = 1;
    bool ban = true;
    fora(1,i,s.size()){
        if(s[i] == s[i-1]){
            con ++;
            ban = false;
        }else{
            if(con%2 != 0){
                res.push_back(s[i-1]);
            }
            con = 1;
        }
    }
    if(con%2 != 0){
            res.push_back(s[s.size()-1]);
    }
    if(ban) return res;
    con = 1;
    return solve(res);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    forn(i, t){
        cin >> u;
        cin >> v;
        int ub = 0, vb = 0;
        string uc, vc;
        forn(i, u.size()){
            if(u[i] == 'B'){
                ub++;
            }else{
                uc.push_back(u[i]);
            }
        }
        forn(i, v.size()){
            if(v[i] == 'B'){
                vb++;
            }else{
                vc.push_back(v[i]);
            }
        }
        if(ub%2 == vb%2 && solve(uc) == solve(vc)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}